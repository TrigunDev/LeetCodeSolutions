class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dpp(n, 1);

        for(int i = 1; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(nums[i] > nums[j]) {
                    dpp[i] = max(dpp[i], dpp[j] + 1);
                }
            }
        }

        return *max_element(dpp.begin(), dpp.end());
    }
};