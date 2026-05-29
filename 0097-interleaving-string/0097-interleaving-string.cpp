class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.size(), n = s2.size(), size = s3.size();

        if(m + n != size) {
            return false;
        }    

        vector<bool> dpp(n + 1, false);
        dpp[0] = true;

        for(int j = 1; j <= n; j++) {
            dpp[j] = dpp[j - 1] && s2[j - 1] == s3[j - 1];
        }

        for(int i = 1; i <= m; i++) {
            dpp[0] = dpp[0] && s1[i - 1] == s3[i - 1];

            for(int j = 1; j <= n; j++) {
                dpp[j] = (dpp[j] && s1[i - 1] == s3[i + j - 1]) || (dpp[j - 1] && s2[j - 1] == s3[i + j - 1]);
            }
        }
        
        return dpp[n];
    }
};