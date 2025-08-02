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
    void convert(TreeNode* root, vector<int>& arrtree){
        if(root==NULL) return;
        arrtree.push_back(root->val);
        if(root->left) convert(root->left, arrtree);
        if(root->right) convert(root->right, arrtree);
    }
    int findfloor(TreeNode* root, int target){
        int ans=-1;
        while(root!=NULL){
            if(root->val==target){
                return root->val;
            }
            else if(root->val>target){
                root=root->left;
            }
            else{
                ans=root->val;
                root=root->right;
            }
        }
        return ans;
    }
    int findceil(TreeNode* root, int target){
        int ans=-1;
        while(root!=NULL){
            if(root->val==target) return root->val;
            else if(root->val>target){
                //poss ceil
                ans=root->val;
                root=root->left;
            }
            else root=root->right;
        }
        return ans;
    }
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        vector<vector<int>>ans;
        if(root==NULL) return ans;
        // vector<int>arrtree;
        // convert(root,arrtree);
        for(auto p: queries){
            int mini= findfloor(root,p);
            int maxi= findceil(root,p);
            ans.push_back({mini,maxi});
        }
        return ans;
    }
};