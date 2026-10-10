class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, 
        int k2) {
        int n = nums1.size(), k = k1 + k2;
        long long result = 0;
        int maxEle = INT_MIN;
        vector<int> diff(n);

        for(int i = 0; i < n; i++) {
            diff[i] = abs(nums1[i] - nums2[i]);
            maxEle = max(maxEle, diff[i]);
        }

        vector<int> freq(maxEle+1, 0);

        for(auto i : diff) {
            freq[i]++;
        }    

        int remove = k; 

        for(int i = maxEle; i > 0 && k; i--) {
            remove = min(k, freq[i]); 
            freq[i] -= remove;
            freq[i-1] += remove;
            k -= remove;
        }


        for(int i = 0; i <= maxEle; i++) {
            result += (long long) i*i*freq[i];
        }    

        return result;
    }
};