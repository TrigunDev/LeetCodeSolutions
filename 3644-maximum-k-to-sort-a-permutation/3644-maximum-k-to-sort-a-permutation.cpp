class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int n = nums.size(), result = INT_MAX;
        bool flag = true;

        for(int i = 0; i < n; i++) {
            if(nums[i] != i) {
                flag = false;
                result &= i;
            }
        }

        if(flag) {
            return 0;
        }

        return result;
    }
};