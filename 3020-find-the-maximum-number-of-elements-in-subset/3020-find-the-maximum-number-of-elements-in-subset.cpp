class Solution {
public:
    int maximumLength(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        unordered_map<long long, int> length, freq;
        int result = 1;

        for(auto it : nums) {
            if(it == 1) {
                freq[1]++;
                continue;
            }

            long long root = sqrt(it);

            if(root * root == it && length.count(root) && freq[root] >= 2) {
                length[it] = length[root] + 2;
            }    
            else {
                length[it] = 1;
            }    

            result = max(result, length[it]);
            freq[it]++;
        }

        if(freq[1]) {
            result = max(result, (freq[1] % 2 ? freq[1] : freq[1] - 1));
        }    

        return result;
    }
};