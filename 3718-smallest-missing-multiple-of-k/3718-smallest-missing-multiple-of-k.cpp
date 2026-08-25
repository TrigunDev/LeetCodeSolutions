class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_map<int, bool> mpp;

        for(auto it : nums) {
            if(it % k == 0) {
                mpp[it/k] = true;
            }
        }

        int i = 1;

        while(1) {
            if(!mpp[i]) {
                return i * k;
            }
            i++;
        }
    }
};