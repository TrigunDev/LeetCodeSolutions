class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid[0][0] == 1) {
            return 0;
        }    

        int row = obstacleGrid.size(), column = obstacleGrid[0].size();

        if(obstacleGrid[row-1][column-1] == 1) {
            return 0;
        }    

        for(int i = 0; i < row; i++) {
            for(int j = 0; j < column; j++) {
                if(obstacleGrid[i][j] == 1) {
                    obstacleGrid[i][j] = -1;
                }
            }
        }

        obstacleGrid[row-1][column-1] = 1;

        for(int i = row-1; i >= 0; i--) {
            for(int j = column-1; j >= 0; j--) {
                if(i == row-1 && j == column-1) {
                    continue;
                }    
                if(obstacleGrid[i][j] == -1) {
                    continue;
                }    
                
                int bottom = 0;

                if(i+1 < row && obstacleGrid[i+1][j] != -1) {
                    bottom = obstacleGrid[i+1][j];
                }
                
                int right = 0;

                if(j+1 < column && obstacleGrid[i][j+1] != -1) {
                    right = obstacleGrid[i][j+1];
                }
                
                long long result = (long long)bottom + (long long)right;
                obstacleGrid[i][j] = (int)result;
            }
        }

        return obstacleGrid[0][0];
    }
};