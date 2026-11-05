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
    set<int> bstElements;
    void dfs(TreeNode* r) {
        if (!r) return;
        bstElements.emplace(r->val);
        dfs(r->left);
        dfs(r->right);
    }
    int kthSmallest(TreeNode* root, int k) {
        dfs(root);
        auto it = std::next(bstElements.begin(), k-1);
        return *it;
    }
};
