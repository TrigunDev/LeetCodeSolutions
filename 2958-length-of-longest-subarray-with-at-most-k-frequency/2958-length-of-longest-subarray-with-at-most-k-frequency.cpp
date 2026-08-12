class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mpp;
        int i = 0, j = 0, result = 0;

        while(j < n) {
            mpp[nums[j]]++;

            while(mpp[nums[j]] > k) {
                mpp[nums[i]]--;
                i++;
            }

            result = max(result, j-i+1);
            j++;
        }

        return result;
    }
};