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
    int prevMax = 0;
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
    }
    int goodNodes(TreeNode* root) {
        if (!root) return 0;
        ++result;
        prevMax = root->val;
        dfs(root->left);
        prevMax = root->val;
        dfs(root->right);
        return result;
    }
};
