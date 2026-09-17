class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        int result = n+1, sum = 0, i = 0;
        vector<int> dpp(n+1, n);

        for(int j = 0; j < n; j++) {
            sum += arr[j];

            while(sum > target) {
                sum -= arr[i++];
            }    

            dpp[j+1] = dpp[j];

            if(sum == target) {
                result = min(result, j-i+1+dpp[i]);
                dpp[j+1] = min(dpp[j], j-i+1);
            }
        }

        if(result == n+1) {
            return -1;
        }
        else {
            return result;
        }
    }
};