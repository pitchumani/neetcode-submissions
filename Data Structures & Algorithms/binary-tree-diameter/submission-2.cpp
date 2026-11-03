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
    int max_diameter = 1;
    int heightOfTree(TreeNode* root) {
        if (!root) return 0;
        int lh = heightOfTree(root->left);
        int rh = heightOfTree(root->right);
        max_diameter = max(max_diameter, lh+rh);
        return max(lh, rh) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        if (!root->left && !root->right) return 0;
        heightOfTree(root);
        return max_diameter; 
    }

};
