class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        int n = grid[0].size();
        int mod = 1e9 + 7;
        vector<int> result(n);  
        result[0] = 1;

        for(auto it : grid) {
            int right = 0; 

            for(int j = 0; j < it.size(); j++) {
                if(it[j]) {  
                    swap(right, result[j]);
                } 
                else {  
                    right = result[j] = (right+result[j]) % mod;
                }
            }
        }

        return result.back();
    }
};