class Solution {
private:
    bool func(vector<vector<int>>& grid, vector<vector<bool>>& visited, int i, int j) {
        int m = grid.size(), n = grid[0].size();

        if(i < 0 || i >= m || j < 0 || j >= n) {
            return false;
        }
        if(visited[i][j]) {
            return true;
        }

        visited[i][j] = true;

        if(grid[i][j] == 1) {
            return true;
        }

        bool isClosed = true;
        isClosed &= func(grid, visited, i-1, j);
        isClosed &= func(grid, visited, i+1, j);
        isClosed &= func(grid, visited, i, j-1);
        isClosed &= func(grid, visited, i, j+1);
        
        return isClosed;
    }

public:
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int answer = 0;
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for(int i = 1; i < m-1; i++) {
            for(int j = 1; j < n-1; j++) {
                if(grid[i][j] == 0 && !visited[i][j]) {
                    bool isClosed = func(grid, visited, i, j);
                    if(isClosed) {
                        answer++;
                    }
                }
            }
        }

        return answer;
    }
};