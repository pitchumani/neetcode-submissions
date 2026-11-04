/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    map<int, queue<TreeNode*>> levelNodes;
    vector<int> getLevelNodes(int level) {
        auto lq = levelNodes[level];
        queue<TreeNode*> nextLevelNodes;
        vector<int> result;
        while(!lq.empty()) {
            auto node = lq.front();
            result.push_back(node->val);
            if (node->left) nextLevelNodes.push(node->left);
            if (node->right) nextLevelNodes.push(node->right);
            lq.pop();
        }
        if (!nextLevelNodes.empty()) levelNodes[level+1] = nextLevelNodes;
        return result;
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (!root) return result;
        levelNodes[0].push(root);
        int level = 0;
        while (levelNodes.find(level) != levelNodes.end()) {
            auto levelQ = levelNodes[level];
            auto nodes = getLevelNodes(level);
            result.push_back(nodes);
            level++;
        }
        return result;
    }
};
