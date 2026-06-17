class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int m = rowSum.size(), n = colSum.size();
        int curRow = 0, curCol = 0;
        vector<vector<int>> result(m, vector<int>(n, 0));

        while(curRow < m || curCol < n) {
            if(curRow >= m) {
                result[m-1][curCol] = colSum[curCol];
                curCol++;
                continue;
            } 
            else if(curCol >= n) {
                result[curRow][n-1] = rowSum[curRow];
                curRow++;
                continue;
            }

            int value = min(rowSum[curRow], colSum[curCol]);
            rowSum[curRow] -= value;
            colSum[curCol] -= value;
            result[curRow][curCol] = value;

            if(rowSum[curRow] == 0) {
                curRow++;
            }
            if(colSum[curCol] == 0) {
                curCol++;
            }
        }

        return result;
    }
};