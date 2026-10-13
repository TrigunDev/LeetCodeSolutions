class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        vector<long long> arr(n);

        for(int i = 0; i < n; i++) {
            arr[i] = 1LL * nums[i] * nums[i];
        }    

        sort(arr.begin(), arr.end());
        long long result = 0;
        int k = n / 2;  
    
        for(int i = 0; i < k; i++) {
            result -= arr[i];
        }    
       
        for(int i = k; i < n; i++) {
            result += arr[i];
        }    

        return result;
    }
};