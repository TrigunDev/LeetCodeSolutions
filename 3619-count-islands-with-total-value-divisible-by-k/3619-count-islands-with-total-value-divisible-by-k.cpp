class Solution {
private:
    long long func(vector<vector<int>>& grid, int i, int j, int n, int m) {
        if(i < 0 || j < 0 || i >= n || j >= m || grid[i][j] == 0) {
            return 0;
        }    

        long long sum = grid[i][j];
        grid[i][j] = 0;

        sum += func(grid, i+1, j, n, m);
        sum += func(grid, i-1, j, n, m);
        sum += func(grid, i, j+1, n, m);
        sum += func(grid, i, j-1, n, m);

        return sum;
    }

public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        int result = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] > 0) {
                    long long sum = func(grid, i, j, n, m);
                    if(sum % k == 0) {
                        result++;
                    }
                }
            }
        }

        return result;
    }
};