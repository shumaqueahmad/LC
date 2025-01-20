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
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;
        int ans=0;
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        while(!q.empty()){
            long long min_ind=q.front().second;
            long long first,last;
            int n=q.size();
            for(int i=0; i<n;i++){
                TreeNode* temp=q.front().first;
                long long curr_id=q.front().second-min_ind;
                q.pop();
                if(i==0) first=curr_id;
                if(i==n-1) last=curr_id;
                if(temp->left!=NULL) q.push({temp->left, curr_id*2+1});
                if(temp->right!=NULL) q.push({temp->right, curr_id*2+2});
            }
            ans=max(ans,int(last-first+1));

        }
        return ans;
    }
};