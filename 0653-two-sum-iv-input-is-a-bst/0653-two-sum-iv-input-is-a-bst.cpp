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

class BSTIterator{
    public:
    stack<TreeNode*> st;
    bool reverse=0;
    //reverse->false : ascending
    //reverse->true : descending
    // Constructor
    BSTIterator(TreeNode* root, bool isReverse){
        reverse=isReverse;
        pushall(root);
    }

    void pushall(TreeNode* root){
        while(root!=NULL){
            st.push(root);
            if(reverse){
                root=root->right;
            }
            else{
                root=root->left;
            }
        }
    }


    int next(){
        TreeNode* temp=st.top();
        st.pop();
        if(reverse){
            pushall(temp->left);
        }
        else{
            pushall(temp->right);
        }
        return temp->val;
    }
};
class Solution {
public:
    void func(TreeNode* root, vector<int> &inor){
        if(root==NULL) return;

        func(root->left,inor);
        inor.push_back(root->val);
        func(root->right,inor);
    }


    bool findTarget(TreeNode* root, int k) {
        if(root==NULL) return false;
        // create 2 objects of BSTIterator class
        BSTIterator left(root,0); //left-> for ascending order : reverse is false
        BSTIterator right(root,1); // right-> for descending order : reverse is true

        int i= left.next();
        int j= right.next(); //gives elements from descending order

        while(i<j){ // not (i<=j) as 2 diff no are req for the sum
            if(i+j==k) return true;
            else if(i+j>k){
                //zada bada hogaya no: reduce the j pointer
                j=right.next();
            }
            else{
                i=left.next();
            }
        }
        return false;
    }
};

/*
vector<int> inor;
        func(root, inor);

        //inor is sorted, store elements in hashmap
        unordered_set<int>s;
        for (int num : inor) {
            int complement = k - num;
            if (s.find(complement) != s.end()) {
                return true;
            }
            s.insert(num);
        }

        return false;
*/