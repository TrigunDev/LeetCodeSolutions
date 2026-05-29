class Solution {
public:
    int minElement(vector<int>& nums) {
        int result = INT_MAX;
        
        for(auto it : nums) {
            int currentSum = 0;
            
            while(it > 0) {
                currentSum += it % 10;
                it /= 10;
            }
            
            result = min(result, currentSum);
        }
        
        return result;
    }
};