class Solution {
public:
    string customSortString(string order, string s) {
        string result = "";
        unordered_map<int, int> mpp;

        for(auto it : s) {
            mpp[it]++;
        }

        for(auto it : order) {
            if(mpp.find(it) != mpp.end()) {
                result.append(mpp[it], it);
                mpp.erase(it);
            }    
        }

        for(auto it : mpp) {
            result.append(it.second, it.first);
        }
        
        return result;
    }
};