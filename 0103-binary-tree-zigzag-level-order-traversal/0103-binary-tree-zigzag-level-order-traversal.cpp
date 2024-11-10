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
    void help(TreeNode* root, vector<vector<int>>& ans) {
        if (root == NULL)
            return;
        int itr = 0;
        queue<TreeNode*> q1;
        q1.push(root);
        bool flag=true;// true-> odd-> L->R and false-> even->R->L
        while (!q1.empty()) {
            int size = q1.size();
            vector<int> temp(size);
            
            for (int i = 0; i < size; i++) {
                TreeNode* node = q1.front();
                q1.pop();
                int index=0;
                if(flag){
                     index=i;
                }
                else{
                     index=size-i-1;
                }
                temp[index]= node->val;
                if (node->left != NULL)
                        q1.push(node->left);
                if (node->right != NULL)
                        q1.push(node->right);
                
            }
            ans.push_back(temp);
            flag=!flag;
        }
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        help(root, ans);
        return ans;
    }
};