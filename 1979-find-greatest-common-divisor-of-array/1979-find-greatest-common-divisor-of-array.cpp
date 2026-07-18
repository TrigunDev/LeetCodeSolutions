class Solution {
public:
    int findGCD(vector<int>& nums) {
        int n = nums.size();
        int minn = 1001, maxx = 1;

        for(int i = 0; i < n; i++) {
            if(nums[i] < minn) {
                minn = nums[i];
            }    
            if(nums[i] > maxx) {
                maxx = nums[i];
            }    
        }
        
        return gcd(minn, maxx);
    }
};