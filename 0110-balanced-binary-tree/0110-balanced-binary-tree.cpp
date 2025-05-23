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
    int high(TreeNode* root){
        if(root==NULL) return 0;

        return 1+max(high(root->left), high(root->right));
    }
    bool isBalanced(TreeNode* root) {
        if(root==NULL) return true;
        int lh=high(root->left);
        int rh=high(root->right);

        if(abs(lh-rh)<=1 && isBalanced(root->left) && isBalanced(root->right)){
            return true;
        }
        return false;
    }
};