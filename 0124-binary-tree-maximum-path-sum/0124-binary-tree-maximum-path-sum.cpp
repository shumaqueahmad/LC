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
    int psum(TreeNode* node,int& maxi){
        if(node==NULL) return 0;
        int lsum=psum(node->left,maxi);
        int rsum=psum(node->right,maxi);

        maxi=max(maxi, lsum+rsum+node->val);
        return max(0,max(lsum,rsum)+node->val);
    }
    int maxPathSum(TreeNode* root) {
        
        int maxi=INT_MIN;
        psum(root,maxi);
        return maxi;
    }
};