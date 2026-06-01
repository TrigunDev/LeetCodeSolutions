class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        vector<vector<int>> dpp(m+1, vector<int>(n+1, 0));

        for(int i = 1; i <= m; i++) {
            dpp[i][0] = i;
        }
        for(int j = 1; j <= n; j++) {
            dpp[0][j] = j;
        }

        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                if(word1[i - 1] == word2[j - 1]) {
                    dpp[i][j] = dpp[i - 1][j - 1];
                } 
                else {
                    dpp[i][j] = min(dpp[i-1][j-1], min(dpp[i][j-1], dpp[i-1][j])) + 1;
                }
            }
        }

        return dpp[m][n];
    }
};