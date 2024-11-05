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
    void func(TreeNode* root, vector<int> &ans){// using recursion
        if(root==nullptr){
            return;
        }
        
        ans.push_back(root->val);
        func(root->left,ans);
        func(root->right,ans);
    }
    //ITERATIVE PREORDER TREAVERSALS
    vector<int> itrpre(TreeNode* root,vector<int>& ans){
        if(root==NULL) return ans;
        stack<TreeNode* >st;
        st.push(root);
        TreeNode *temp;
        while(!st.empty()){
            temp=st.top();
            st.pop();
            ans.push_back(temp->val);
            if(temp->right !=NULL) st.push(temp->right);
            if(temp->left !=NULL) st.push(temp->left);
        }
        return ans;

    }
    vector<int> preorderTraversal(TreeNode* root) {
       
        vector<int> ans;
        //func(root, ans);

        return itrpre(root,ans);
    }
};