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
    int count = 0;
    int kthSmallest(TreeNode* root, int k) {
        TreeNode *curr = root;
        stack<TreeNode*> nstack;
        while(curr || !nstack.empty()) {
            while (curr) {
                nstack.push(curr);
                curr = curr->left;
            }
            curr = nstack.top();
            nstack.pop();
            count++;
            if (count == k) return curr->val;
            curr = curr->right;
        }
        return -1;
    }
};
