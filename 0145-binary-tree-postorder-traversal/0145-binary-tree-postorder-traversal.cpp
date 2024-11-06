/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    void func(TreeNode* root, vector<int>& ans) {
        if (root == nullptr) {
            return;
        }
        func(root->left, ans);
        func(root->right, ans);
        ans.push_back(root->val);
    }

    vector<int> itrpost(TreeNode* root, vector<int> ans) {
        if (root == NULL)
            return ans;
        stack<TreeNode*> st;
        TreeNode* curr = root;
        
        TreeNode* temp = NULL;

        while (!st.empty() || curr != NULL) {
            if (curr != NULL) {
                st.push(curr);
                curr = curr->left;
            } else {
                temp = st.top()->right;
                if (temp == NULL) {
                    temp = st.top();
                    st.pop();
                    ans.push_back(temp->val);

                    while (!st.empty() && temp == st.top()->right) {//returning to root node
                        temp = st.top();
                        st.pop();
                        ans.push_back(temp->val);
                    }
                } else {
                    curr = temp;
                }
            }
        }
        return ans;
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        //func(root, ans);
        return itrpost(root,ans);
    }
};