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
    bool is_balanced = false;
    std::pair<bool, int> dfs(TreeNode *root) {
        if (!root) return std::make_pair<bool, int>(true, 0);
        auto left = dfs(root->left);
        auto right = dfs(root->right);
        bool balanced = left.first && right.first && abs(left.second - right.second) <= 1;
        int node_height = max(left.second, right.second) + 1;
        return std::make_pair<bool, int>(std::move(balanced), std::move(node_height));
    }

    bool isBalanced(TreeNode* root) {
        if (!root) return true;
        auto result = dfs(root);
        return result.first;
    }
};
