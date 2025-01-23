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
    void func(TreeNode* root, int &ans){
        if(root==NULL || root->left==NULL && root->right==NULL) return;

        if(root->left!=NULL && (root->left->left==NULL && root->left->right==NULL)){
            ans+=root->left->val;
        }
        func(root->left,ans);
        func(root->right, ans);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        
        int ans=0;
        func(root, ans);
        return ans;
    }
};