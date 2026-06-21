class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(),costs.end());
        int result = 0;

        for(auto it : costs) {
            if(it > coins) {
                break;
            }

            result++;
            coins -= it;
        }

        return result;
    }
};