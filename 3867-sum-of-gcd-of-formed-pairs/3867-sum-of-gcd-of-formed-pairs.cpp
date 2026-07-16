class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefixGcd(n);
        int maxx = 0;

        for(int i = 0; i < n; i++) {
            maxx = max(maxx, nums[i]);
            prefixGcd[i] = gcd(nums[i], maxx);
        }

        sort(prefixGcd.begin(), prefixGcd.end());
        long long result = 0;
        int low = 0, high = n-1;

        while(low < high) {
            result += gcd(prefixGcd[low++], prefixGcd[high--]);
        }

        return result;
    }
};