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
    int result = 0;
    int prevMax = -110;/*
    void dfs(TreeNode* r) {
        if (!r) return;
        if (r->val >= prevMax) {
            ++result;
            prevMax = r->val;
        }
        int bkMax = prevMax;
        dfs(r->left);
        prevMax = bkMax;
        dfs(r->right);
    }*/
    int goodNodes(TreeNode* root) {
        if (!root) return result;
        if (root->val >= prevMax) {
            ++result;
            prevMax = root->val;
        }
        int bk = prevMax;
        goodNodes(root->left);
        prevMax = bk;
        goodNodes(root->right);
        return result;
    }
};
