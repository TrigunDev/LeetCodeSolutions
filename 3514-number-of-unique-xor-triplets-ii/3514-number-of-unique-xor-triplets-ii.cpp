class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int maxXor = 2048;
        vector<vector<int>> dpp(4, vector<int>(maxXor, 0));
        dpp[0][0] = 1;

        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < maxXor; j++) {
                if(!dpp[i][j]) {
                    continue;
                }    

                for(auto it : nums) {
                    dpp[i+1][j^it] = 1;
                }
            }
        }

        int result = 0;

        for(int i = 0; i < maxXor; i++) {
            if(dpp[3][i]) {
                result++;
            }
        }

        return result;
    }
};