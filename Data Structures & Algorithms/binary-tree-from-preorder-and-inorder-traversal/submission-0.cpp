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
    unordered_map<int, int> inMap;
    TreeNode* placeNode(vector<int>& preorder, int& pidx, int inStart, int inEnd) {
        if (inStart > inEnd) return nullptr;
        int rval = preorder[pidx]; pidx++;
        int inIdx = inMap[rval];
        TreeNode *root = new TreeNode(rval);
        root->left = placeNode(preorder, pidx, inStart, inIdx-1);
        root->right = placeNode(preorder, pidx, inIdx+1, inEnd);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); ++i) {
            inMap[inorder[i]] = i;
        }
        int pidx = 0;
        return placeNode(preorder, pidx, 0, preorder.size()-1);
    }
};
