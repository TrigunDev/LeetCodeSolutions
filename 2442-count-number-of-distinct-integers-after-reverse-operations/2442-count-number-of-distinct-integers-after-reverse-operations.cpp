class Solution {
public:
    int countDistinctIntegers(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> set(nums.begin(), nums.end());

        for(int i = 0; i < n; i++) {
            string s = to_string(nums[i]);
            reverse(s.begin(), s.end());
            set.insert(stoi(s));
        }
        
        int result = set.size();

        return result;
    }
};