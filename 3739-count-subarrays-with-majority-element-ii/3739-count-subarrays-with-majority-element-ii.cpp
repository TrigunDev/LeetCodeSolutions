class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        int temp = n;

        vector<int> freq(2 * n + 1);
        freq[n] = 1;

        long long less = 0, result = 0;

        for(auto it : nums) {
            if(it == target) {
                less += freq[temp++];
            }    
            else {
                less -= freq[--temp];
            }    

            ++freq[temp];
            result += less;
        }

        return result;
    }
};