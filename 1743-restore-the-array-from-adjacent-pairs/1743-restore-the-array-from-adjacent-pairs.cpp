class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int, vector<int>> mpp;

        for(auto it : adjacentPairs) {
            mpp[it[0]].push_back(it[1]);
            mpp[it[1]].push_back(it[0]);
        }

        vector<int> result;

        for(auto [num, it] : mpp) {
            if(it.size() == 1){
                result.push_back(num);
                result.push_back(it[0]);
                break;
            }
        }

        int i = 1, n = mpp.size();

        while(i < n-1) {
            auto it = mpp[result[i]];

            if(it[0] != result[i-1]) {
                result.push_back(it[0]);
            } 
            else {
                result.push_back(it[1]);
            }

            i++;
        }

        return result;
    }
};