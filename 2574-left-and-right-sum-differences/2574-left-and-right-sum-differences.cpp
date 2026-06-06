class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);
        int rightSum = 0, leftSum = 0;
        
        for(auto it : nums) {
            rightSum += it;
        }
        
        for(int i = 0; i < n; i++) {
            rightSum -= nums[i]; 
            result[i] = abs(leftSum - rightSum);
            leftSum += nums[i];  
        }
        
        return result;
    }
};