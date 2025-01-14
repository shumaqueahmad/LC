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
    void func(TreeNode* root, vector<int>& ans){
        if(root==nullptr){
            return;
        }
        func(root->left,ans);
        ans.push_back(root->val);
        func(root->right, ans);
    }
    vector<int> itrin(TreeNode * root, vector<int> ans){
        if(root==NULL) return ans;
        stack<TreeNode*> st;
        TreeNode* temp= root;
        while(true){
            if(temp !=NULL){
                st.push(temp);
                temp=temp->left;
            }
            else{
                if(st.empty()==true) break;
                temp=st.top();
                ans.push_back(temp->val);
                st.pop();

                temp=temp->right;
            }
        }
        
        return ans;
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        //func(root,ans);
        return itrin(root,ans);
    }
};