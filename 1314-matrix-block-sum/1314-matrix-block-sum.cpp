class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> result(n, vector<int>(m));

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                int sum = 0;
                for(int o = max(0, i-k); o <= min(n-1, i+k); o++) {
                    for(int p = max(0, j-k); p <= min(m-1, j+k); p++) {
                        sum += mat[o][p];
                    }
                }

                result[i][j] = sum;
            }
        }

        return result;
    }
};