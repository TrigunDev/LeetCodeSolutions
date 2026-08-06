class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        unordered_set<int> seen(nums.begin(), nums.end());
        int minn = *min_element(nums.begin(), nums.end());
        int maxx = *max_element(nums.begin(), nums.end());
        vector<int> result;

        for(int i = minn; i <= maxx; i++) {
            if(!seen.count(i)) {
                result.push_back(i);
            }
        }

        return result;
    }
};