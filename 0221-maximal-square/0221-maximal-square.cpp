class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dpp(m+1, vector<int>(n+1, 0));
        int result = 0, finalResult = 0;
        
        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                if(matrix[i-1][j-1] == '0') {
                    dpp[i][j] = 0;
                }
                else {
                    dpp[i][j] = 1 + min(dpp[i-1][j], min(dpp[i][j-1], dpp[i-1][j-1]));
                }
                
                result = max(result, dpp[i][j]);
                finalResult = result * result;
            }
        }
        
        return finalResult;
    }
};