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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==NULL) return false;
        // bool check=false;

        if(root->left==NULL && root->right==NULL){
            return (root->val==targetSum);
        }
        bool leftsum= hasPathSum(root->left, targetSum-root->val);
        bool rightsum=hasPathSum(root->right, targetSum-root->val);
        
        return leftsum || rightsum;
    }
};