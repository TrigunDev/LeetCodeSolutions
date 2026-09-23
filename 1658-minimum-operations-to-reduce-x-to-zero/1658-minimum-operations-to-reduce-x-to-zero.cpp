class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int k = reduce(nums.begin(), nums.end()) - x;

        if(k < 0) {
            return -1;
        }     
        if(k == 0) {
            return n;
        }    

        int temp = -1, i = 0, sum = 0;

        for(int j = 0; j < n; j++) {
            sum += nums[j];

            while(sum > k) {
                sum -= nums[i];
                i++;
            }    

            if(sum == k) {
                temp = max(temp, j-i+1);
            }    
        }

        if(temp+1) {
            return n-temp;
        }
        else {
            return -1;
        }
    }
};