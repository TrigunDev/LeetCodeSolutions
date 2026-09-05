class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> temp = nums;
        vector<int> suffixMin(n);
        suffixMin[n-1] = temp[n-1];

        for(int i = n-2; i >= 0; i--) {
            suffixMin[i] = min(suffixMin[i+1], temp[i]);
        }

        int prefixMax = temp[0];

        for(int i = 0; i < n; i++) {
            prefixMax = max(prefixMax, temp[i]);
            if(prefixMax - suffixMin[i] <= k) {
                return i;
            }
        }

        return -1;
    }
};