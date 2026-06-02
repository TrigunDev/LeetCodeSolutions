class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int firstBuy = -prices[0], firstSell = 0;
        int secondBuy = -prices[0], secondSell = 0;

        for(int i = 1; i < n; i++) {
            int price = prices[i];
            firstBuy = max(firstBuy, -price);
            firstSell = max(firstSell, firstBuy + price);
            secondBuy = max(secondBuy, firstSell - price);
            secondSell = max(secondSell, secondBuy + price);
        }

        return secondSell;        
    }
};