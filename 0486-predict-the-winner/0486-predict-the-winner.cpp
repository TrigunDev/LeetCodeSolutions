class Solution {
public:
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        
        if(n % 2 == 0) {
            return true; 
        }    
        
        vector<int> dpp(nums);

        for(int i = n-2; i >= 0; i--) {
            for(int j = i+1; j < n; j++) {
                dpp[j] = max(nums[i] - dpp[j], nums[j] - dpp[j-1]);
            }
        }
        
        return dpp[n-1] >= 0;
    }
};