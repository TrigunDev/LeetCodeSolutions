class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        unordered_map<string, int> freq;
        
        for(auto it : matrix) {
            string pattern;

            if(it[0] == 0) {
                for(auto bit : it) {
                    pattern += to_string(bit);
                }    
            } 
            else {
                for(auto bit : it) {
                    pattern += to_string(bit ^ 1);
                }    
            }

            freq[pattern]++;
        }
        
        int result = 0;

        for(auto it : freq) {
            result = max(result, it.second);
        }

        return result;
    }
};