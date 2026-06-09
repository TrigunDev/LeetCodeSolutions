class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int n = nums.size();
        int minn = INT_MAX, maxx = INT_MIN;

        for(int i = 0; i < n; i++) {
            if(nums[i] < minn) {
                minn = nums[i];
            }
            if(nums[i] > maxx) {
                maxx = nums[i];
            }
        }

        long long result = (long long) k * (maxx - minn);

        return result;
    }
};