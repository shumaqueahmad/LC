class Solution {
public:
    vector<int> zigzagTraversal(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> ans;
        bool flag = true;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int col = 0;
                if (flag) {
                    if (i % 2 == 0) {
                        col = j;
                    } else {
                        col = m - j - 1;
                    }
                    ans.push_back(grid[i][col]);
                }
                flag = !flag;
            }
        }
        return ans;
    }
};