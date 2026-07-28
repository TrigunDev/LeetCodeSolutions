class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxx1 = INT_MIN, maxx2 = INT_MIN;

        for(auto it : nums) {
            if(it >= maxx1) {
                maxx2 = maxx1;
                maxx1 = it;
            } 
            else if(it > maxx2) {
                maxx2 = it;
            }
        }

        int result = (maxx1-1) * (maxx2-1);

        return result;
    }
};