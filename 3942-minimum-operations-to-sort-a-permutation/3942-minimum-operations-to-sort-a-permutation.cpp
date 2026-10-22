class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int shift1 = -1;
        bool ok1 = true;

        for(int i = 0; i < n; i++) {
            if(nums[i] == 0) {
                shift1 = i;
                break;
            }
        }

        for(int i = 0; i < n; i++) {
            if(nums[(i + shift1) % n] != i) {
                ok1 = false;
                break;
            }
        }

        int result = 1e9;

        if(ok1) {
            result = min(result, shift1);
            
            if(shift1 > 0) {
                result = min(result, n - shift1 + 2);
            }
            else {
                result = min(result, 2);
            }
        }

        reverse(nums.begin(), nums.end());

        int shift2 = -1;
        bool ok2 = true;

        for(int i = 0; i < n; i++) {
            if(nums[i] == 0) {
                shift2 = i;
                break;
            }
        }

        for(int i = 0; i < n; i++) {
            if(nums[(i + shift2) % n] != i) {
                ok2 = false;
                break;
            }
        }

        if(ok2) {
            result = min(result, 1 + shift2);
            result = min(result, n - shift2 + 1);
        }

        return result == 1e9 ? -1 : result;
    }
};