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
        //level order to mark parents in map
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* temp=q.front();
            q.pop();
            if(temp->left){
                parent[temp->left]= temp;
                q.push(temp->left);
            }
            if(temp->right){
                parent[temp->right]= temp;
                q.push(temp->right);
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent;
        markparent(root,parent);
        int count=0;

        //creating a visited map
        unordered_map<TreeNode*,int>visit;
        queue<TreeNode*>q;
        q.push(target);
        visit[target]=1;
        while(!q.empty()){
            int n=q.size();
            if(count==k) break;
            count++; //incrementing count as now i am going to move 1 step away from target
            
            for(int i=0; i<n; i++){
                TreeNode* temp=q.front();
                q.pop();

                if(temp->left && visit[temp->left]!=1){
                    visit[temp->left]=1;
                    q.push(temp->left);
                }
                if(temp->right && visit[temp->right]!=1){
                    visit[temp->right]=1;
                    q.push(temp->right);
                }
                if(parent[temp] && visit[parent[temp]]!=1){
                    visit[parent[temp]]=1;
                    q.push(parent[temp]);
                }
            }
        }
        vector<int> ans;
        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};