class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int minn = min_element(nums.begin(), nums.end()) - nums.begin();
        int maxx = max_element(nums.begin(), nums.end()) - nums.begin();
        int low = min(minn, maxx), high = max(minn, maxx);
        int front = high+1, back = n-low;
        int Both = (low+1) + (n-high);

        int result = min({front, back, Both});

        return result;
    }
};