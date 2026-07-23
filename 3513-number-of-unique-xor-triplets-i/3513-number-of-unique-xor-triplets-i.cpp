class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        
        if(n <= 2) {
            return n;
        }

        int mask = 0;

        for(auto it : nums) {
            mask |= it;
        }

        int result = mask + 1;

        return result;
    }
};