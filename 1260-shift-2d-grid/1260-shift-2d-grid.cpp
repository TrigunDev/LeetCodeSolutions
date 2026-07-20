class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m=grid.size(), n=grid[0].size();
        int temp = m*n;
        k %= temp;
        vector<vector<int>> result(m, vector<int>(n));

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                int oldIdx = i*n+j, newIdx = (oldIdx+k) % temp;
                result[newIdx/n][newIdx%n] = grid[i][j];
            }
        }

        return result;
    }
};