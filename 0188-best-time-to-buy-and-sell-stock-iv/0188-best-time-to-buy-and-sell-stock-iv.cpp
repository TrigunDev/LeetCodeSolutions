class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        vector<int> buy(k+1, INT_MAX);
        vector<int> maxProfit(k+1, 0);

        for(auto it : prices) {
            for(int i = 1; i <= k; i++) {
                buy[i] = min(buy[i], it - maxProfit[i-1]);
                maxProfit[i] = max(maxProfit[i], it - buy[i]);
            }
        }

        return maxProfit[k];
    }
};