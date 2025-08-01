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
    TreeNode* markparent(TreeNode* root,unordered_map<TreeNode*, TreeNode*>& parent,int start){
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* addr=NULL;
        while(!q.empty()){
            auto temp=q.front();
            if(temp->val==start) addr= temp;
            q.pop();
            if(temp->left){
                q.push(temp->left);
                parent[temp->left]=temp;
            }
            if(temp->right){
                q.push(temp->right);
                parent[temp->right]=temp;
            }
        }
        return addr;
    }
    int amountOfTime(TreeNode* root, int start) {
        if(root==NULL) return 0;
        unordered_map<TreeNode*, TreeNode*>parent;
        TreeNode* startadd= markparent(root,parent,start);
        queue<TreeNode*>q;
        unordered_map<TreeNode*,int>m1;
        q.push(startadd);
        m1[startadd]=1;
        int count=0;
        int flag=0;
        while(!q.empty()){
            int n=q.size();
            for(int i=0; i<n; i++){
                auto temp=q.front();
                q.pop();
                flag=0;
                if(temp->left!=NULL && m1[temp->left]!=1){
                    q.push(temp->left);
                    m1[temp->left]=1;
                    flag=1;
                }
                if(temp->right!=NULL && m1[temp->right]!=1){
                    q.push(temp->right);
                    m1[temp->right]=1;
                    flag=1;
                }
                if(parent[temp]!=NULL && m1[parent[temp]]!=1){
                    q.push(parent[temp]);
                    m1[parent[temp]]=1;
                    flag=1;
                }
            }
            if(flag)count++;
        }

        return count;
    }
};