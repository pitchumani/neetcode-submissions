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
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return nullptr;
        TreeNode *nleft = nullptr;
        if (root->left) nleft = invertTree(root->left);
        TreeNode *nright = nullptr;
        if (root->right) nright = invertTree(root->right);
        root->left = nright; //nright ? nright : right;
        root->right = nleft; //nleft ? nleft : left;
        return root;
    }
};
