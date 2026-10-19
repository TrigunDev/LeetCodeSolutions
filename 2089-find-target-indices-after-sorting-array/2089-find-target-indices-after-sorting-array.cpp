class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int n = nums.size();
        int countLess = 0, countGreater = 0;
        vector<int> result;

        for(auto it : nums) {
            if(it < target) {
                countLess++;
            }
            else if(it > target) {
                countGreater++;
            }
        }

        int temp = n - countGreater - countLess;

        for(int i = 0; i < temp; i++) {
            result.push_back(i + countLess);
        }

        return result;
    }
};