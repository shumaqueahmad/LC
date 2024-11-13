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
    void func(TreeNode* root, stack<TreeNode*>& s1){
        if(root==NULL) return;
        if(root->left==NULL && root->right==NULL){
            s1.push(root);
            return;
        }
        s1.push(root);
        if(root->right!=NULL){
            func(root->right, s1);
        }
        else{
            func(root->left,s1);
        }
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(root==NULL) return ans;
        stack<TreeNode*> s1;
        // func(root,s1);
        // while(!s1.empty()){
        //     ans.push_back(s1.top()->val);
        //     s1.pop();
        // }
        // reverse(ans.begin(), ans.end());
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size=q.size();

            for(int i=1;i<=size;i++){
                TreeNode* temp=q.front();
                q.pop();
                if(i==size){
                    ans.push_back(temp->val);
                }
                if(temp->left!=NULL) q.push(temp->left);
                if(temp->right!=NULL) q.push(temp->right);
            }
        }
        return ans;

    }
};