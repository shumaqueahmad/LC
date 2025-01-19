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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL) return ans;
        map<int, map<int, multiset<int>>> m1; // {vertical, {level, {node values}}}

        // Queue for level-order traversal
        queue<pair<TreeNode*, pair<int, int>>> q; // {node, {vertical, level}}
        q.push({root, {0, 0}});

        // Perform BFS traversal
        while (!q.empty()) {
            auto temp = q.front();
            q.pop();

            TreeNode* node = temp.first;
            int x = temp.second.first;  // Vertical position
            int y = temp.second.second; // Level position

            // Insert the node value into the map
            m1[x][y].insert(node->val);

            // Push left and right children into the queue
            if (node->left) q.push({node->left, {x - 1, y + 1}});
            if (node->right) q.push({node->right, {x + 1, y + 1}});
        }

        // Extract the values from the map into the result vector
        for (auto& [vertical, levels] : m1) {
            vector<int> column;
            for (auto& [level, nodes] : levels) {
                column.insert(column.end(), nodes.begin(), nodes.end());
            }
            ans.push_back(column);
        }
        return ans;

    }
};