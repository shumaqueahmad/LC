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
    int height(TreeNode* root,int &maxi){
        if(root==NULL) return 0;

        int l=height(root->left,maxi);
        int r=height(root->right,maxi);

        maxi=max(maxi,l+r);


        return 1+max(l,r);
    }
    // int help(TreeNode* root, int &maxi){
    //     if(root==NULL) return 0;
    //     int lh=height(root->left);
    //     int rh=height(root->right);

    //     maxi=max(maxi,lh+rh);
    //     help(root->left,maxi);
    //     help(root->right,maxi);
    //     return maxi;

    // }
    int diameterOfBinaryTree(TreeNode* root) {
        //base:
        
        int maxi=0;
        height(root,maxi);
        
        return maxi;
    }
};