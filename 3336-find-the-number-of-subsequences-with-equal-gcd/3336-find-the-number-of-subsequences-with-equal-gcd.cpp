class Solution {
private:
    long long mod = 1e9 + 7;
  
    int func(int i, int s1, int s2, vector<int> &nums, vector<vector<vector<int>>> &dpp) {
        if(i >= nums.size()) {
            if(s1 != 0 && s2 != 0 && s1 == s2) {
                return 1;
            }

            return 0;
        }
        if(dpp[i][s1][s2] != -1) {
            return dpp[i][s1][s2];
        }
        
        int a = func(i+1, s1, s2, nums, dpp);
        int b = func(i+1, __gcd(s1, nums[i]), s2,nums, dpp);
        int c = func(i+1, s1, __gcd(s2, nums[i]), nums, dpp);

        return dpp[i][s1][s2] = ((b+c) % mod + a) % mod;
    }

public:
    int subsequencePairCount(vector<int>& nums) {
        int n = nums.size();
        int maxx = *max_element(nums.begin(), nums.end());
        vector<vector<vector<int>>> dpp(n, vector<vector<int>>(maxx+1, vector<int>(maxx+1, -1)));

        return func(0, 0, 0, nums, dpp);
    }
};