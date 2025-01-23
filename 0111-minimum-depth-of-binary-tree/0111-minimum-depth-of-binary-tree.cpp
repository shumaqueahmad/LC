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
    int minDepth(TreeNode* root) {
        if(root==NULL) return 0;
        if(root->left==NULL && root->right==NULL) return 1;//for leaf node return 1;

        int lh= minDepth(root->left);
        int rh= minDepth(root->right);

        if(root->left==NULL) return 1+rh; // if left is null return for only the right child
        if(root->right==NULL) return 1+lh;// vice versa
        return 1+min(lh,rh);
    }
};