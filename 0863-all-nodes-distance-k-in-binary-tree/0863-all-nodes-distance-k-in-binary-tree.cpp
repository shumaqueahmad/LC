/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void markparent(TreeNode* root,unordered_map<TreeNode*, TreeNode*>& parent){
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            auto temp=q.front();
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
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        if(root==NULL) return ans;
        unordered_map<TreeNode*, TreeNode*>parent;
        markparent(root,parent);

        queue<TreeNode*>q;
        unordered_map<TreeNode*, int>m1;
        q.push(target);
        m1[target]=1;
        int count=0;
        while(!q.empty()){
            int n=q.size();
            if(count==k) break;
            count++;
            for(int i=0; i<n; i++){
                auto temp=q.front();
                q.pop();
                if(temp->left!=NULL && m1[temp->left]!=1){
                    q.push(temp->left);
                    m1[temp->left]=1;
                }
                if(temp->right!=NULL && m1[temp->right]!=1){
                    q.push(temp->right);
                    m1[temp->right]=1;
                }
                if(parent[temp]!=NULL && m1[parent[temp]]!=1){
                    q.push(parent[temp]);
                    m1[parent[temp]]=1;
                }
            }
        }

        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};