class Solution {
private:
    int solve(vector<vector<int>>& grid, vector<vector<bool>>& visit, int i, int j) {
        int rows = grid.size(), columns = grid[0].size();

        if(i < 0 || i >= rows || j < 0 || j >= columns || visit[i][j] || grid[i][j] == 0) {
            return 0;
        }

        visit[i][j] = true;

        return 1 + solve(grid, visit, i+1, j) + solve(grid, visit, i-1, j) + solve(grid, visit, i, j+1) + solve(grid, visit, i, j-1);
    }

public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int rows = grid.size(), columns = grid[0].size();
        vector<vector<bool>> visit(rows, vector<bool>(columns, false));
        int result = 0;

        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < columns; j++) {
                if(grid[i][j] == 1 && !visit[i][j]) {
                    result = max(result, solve(grid, visit, i, j));
                }
            }
        }

        return result;        
    }
};