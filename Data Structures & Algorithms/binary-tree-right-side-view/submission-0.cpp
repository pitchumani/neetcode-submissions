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
    queue<TreeNode*> levelNodes;
    int getRightMost() {
        auto node = levelNodes.back();
        int result = node->val;
        int len = levelNodes.size();
        int idx = 0;
        while (idx < len) {
            auto node = levelNodes.front();
            if (node->left) levelNodes.push(node->left);
            if (node->right) levelNodes.push(node->right);
            levelNodes.pop();
            idx++;
        }
        return result;
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        if (!root) return result;
        levelNodes.push(root);
        while (!levelNodes.empty()) {
            result.push_back(getRightMost());
        }
        return result;
    }
};
