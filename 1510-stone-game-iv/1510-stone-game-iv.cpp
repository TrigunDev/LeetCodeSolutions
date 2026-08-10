class Solution {
public:
    bool winnerSquareGame(int n) {
        bool dpp[n+1];

        for(int i = 0; i <= n; i++) {
            dpp[i] = false;
        }

        for(int i = 0; i <= n; i++) {
            if(!dpp[i]) {
                for(int j = 1; i+j*j <= n; j++) {
                    dpp[i+j*j] = true;
                }

                if(dpp[n]) {
                    return true;
                }
            }
        }

        return false;
    }
};