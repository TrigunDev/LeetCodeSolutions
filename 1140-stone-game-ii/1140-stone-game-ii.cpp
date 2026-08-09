class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<int> suffixSum(n, 0);
        suffixSum[n-1] = piles[n-1];

        for(int i = n-2; i >= 0; i--) {
            suffixSum[i] = suffixSum[i+1] + piles[i];
        }
        
        vector<vector<int>> dpp(n, vector<int>(n+1, 0));
      
        for(int i = n-1; i >= 0; i--) { 
            for(int m = 1; m <= n; m++) {
                if (i+2*m >= n) {
                    dpp[i][m] = suffixSum[i];
                } 
                else {
                    for(int j = 1; j <= 2*m; j++) {
                        int next = max(m, j);
                        int myScore = suffixSum[i] - dpp[i+j][next];
                        dpp[i][m] = max(dpp[i][m], myScore);
                    }
                }
            }
        }
        
        return dpp[0][1];
    }
};