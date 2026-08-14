class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = 1, result = 1;

        while(j < n) {
            if(nums[j] == nums[j-1]) {
                j++;
                continue;
            }

            nums[i+1] = nums[j];
            result++;
            j++;
            i++; 
        }

        return result;
    }
};