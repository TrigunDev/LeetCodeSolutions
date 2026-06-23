class Solution {
public:
    int zigZagArrays(int n, int l, int r) {
        long long MOD = 1000000007;
        int temp = r - l + 1;
        vector<int> dpp(temp, 1);

        for(int i = 2; i <= n; i++) {
            reverse(dpp.begin(), dpp.end());
            int sum = 0;

            for(auto& it : dpp) {
                sum = (sum + exchange(it, sum)) % MOD;
            }    
        }

        return ((accumulate(dpp.begin(), dpp.end(), 0LL) % MOD) << 1) % MOD;
    }
};