class Solution {
long long mod = 1e9 + 7;

public:
    int maxSum(vector<int>& nums, int k) {
        vector<int> bitCount(32, 0);

        for(int num : nums) {
            for(int i = 0; i < 32; i++) {
                if(num & (1 << i)) {
                    bitCount[i]++;
                }
            }
        }

        vector<int> largestK(k, 0); 

        for(int i = 31; i >= 0; i--) {
            int count = bitCount[i];

            for(int j = 0; j < k && count > 0; j++) {
                largestK[j] |= (1 << i);
                count--;
            }
        }

        long long result = 0;
      
        for(int num : largestK) {
            result = (result + 1LL*num*num%mod) % mod;
        }

        return result;
    }
};