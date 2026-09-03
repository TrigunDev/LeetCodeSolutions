class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int odd = INT_MAX, even = INT_MAX;

        for(auto it : nums1) {
            if(it % 2 == 0) {
                even = min(even, it);
            } 
            else {
                odd = min(odd, it);
            }
        }

        if(odd == INT_MAX) {
            return true;
        }

        return odd < even;
    }
};