class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        int n = nums.size();

        for(int i = 0; i < n; i++) {
            int element = nums[i], sum = 0;

            while(element > 0) {
                sum += element % 10;
                element /= 10;
            }

            if(sum == i) {
                return i;
            }    
        }
        
        return -1;
    }
};