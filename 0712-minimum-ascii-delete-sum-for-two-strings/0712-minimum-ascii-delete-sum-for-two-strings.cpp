class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        vector<vector<int>> dpp(n+1, vector<int>(m+1, 0));

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(s1[i] == s2[j]) {
                    dpp[i+1][j+1] = dpp[i][j] + s1[i];
                }    
                else {
                    dpp[i+1][j+1] = max(dpp[i][j+1], dpp[i+1][j]);
                }    
            }
        }

        int result = 0;

        for(auto it : s1) {
            result += it;
        }  

        for(auto it : s2) {
            result += it;
        }    

        return result - 2*dpp[n][m];
    }
};