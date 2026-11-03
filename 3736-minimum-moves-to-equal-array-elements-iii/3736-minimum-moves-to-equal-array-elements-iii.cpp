class Solution {
public:
    long long minMoves(vector<int>& nums) {
        int maxx = *max_element(nums.begin(), nums.end());
        int result = 0;

        for(auto it : nums) {
            result += (maxx - it);
        }

        return result;
    }
};