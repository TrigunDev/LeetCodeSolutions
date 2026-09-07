class Solution {
public:
    int distinctSubseqII(string s) {
        int n = s.size();
        int mod = 1e9 + 7;
        vector<int> dpp(n, 1);
        int result = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(s[i] != s[j]) {
                    dpp[i] = (dpp[i] + dpp[j]) % mod;
                }
            }

            result = (result + dpp[i]) % mod;
        }
        
        return result;
    }
};