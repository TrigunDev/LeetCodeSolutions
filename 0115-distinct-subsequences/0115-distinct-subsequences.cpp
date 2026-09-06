class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.size(), n = t.size();
        vector<int> dpp(n+1, 0);
        int mod = (int) 1e9 + 7; 

        for(int i = 1; i <= m; i++) {
            int count = 1;

            for(int j = 1; j <= n; j++) {
                int current = dpp[j]; 
                int take = 0, notTake = 0;

                if(s[i-1] == t[j-1]) {
                    take = count;
                }

                notTake = current;
                dpp[j] = (take + notTake) % mod;
                count = current;
            }
        }
        
        return dpp[n];
    }
};