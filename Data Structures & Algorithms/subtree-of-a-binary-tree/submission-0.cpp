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
    bool isSameTree(TreeNode* first, TreeNode* second) {
        if (!first && !second) return true;
        if (first && second) {
            return first->val == second->val && isSameTree(first->right, second->right) && isSameTree(first->left, second->left);
        }
        return false;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root) return false;
        if (!subRoot) return true;
        if (isSameTree(root, subRoot)) return true;
        if (isSubtree(root->left, subRoot)) return true;
        if (isSubtree(root->right, subRoot)) return true;
        return false;
    }
};
