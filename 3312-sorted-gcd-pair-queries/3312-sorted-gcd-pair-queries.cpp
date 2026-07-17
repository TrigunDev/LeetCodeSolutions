class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int maxValue = *max_element(nums.begin(), nums.end());
        vector<long long> freq(maxValue+1, 0);

        for(auto it : nums) {
            freq[it]++;
        }    

        vector<long long> divCount(maxValue+1, 0);

        for(int i = 1; i <= maxValue; i++) {
            for(int j = i; j <= maxValue; j += i) {
                divCount[i] += freq[j];
            }    
        }

        vector<long long> exact(maxValue+1, 0);

        for(int i = maxValue; i >= 1; i--) {
            exact[i] = divCount[i] * (divCount[i] - 1) / 2;
            for(int j = 2 * i; j <= maxValue; j += i) {
                exact[i] -= exact[j];
            }    
        }

        vector<long long> prefix(maxValue+1, 0);

        for(int i = 1; i <= maxValue; i++) {
            prefix[i] = prefix[i-1] + exact[i];
        }    

        vector<int> result;

        for(auto q : queries) {
            int it = lower_bound(prefix.begin()+1, prefix.end(), q+1) - prefix.begin();
            result.push_back(it);
        }

        return result;
    }
};