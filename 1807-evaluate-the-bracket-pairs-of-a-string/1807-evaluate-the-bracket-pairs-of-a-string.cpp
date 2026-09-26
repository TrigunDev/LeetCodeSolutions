class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> mpp;

        for(auto it : knowledge) {
            mpp[it[0]] = it[1];
        }

        string key = "", result = "";
        bool flag = false;

        for(char it : s) {
            if(it == '(') {
                flag = true;
            }
            else if(it == ')') {
                if(mpp.find(key) != mpp.end()) {
                    result += mpp[key];
                }
                else {
                    result += "?";
                }

                flag = false;
                key = "";
            }
            else if(flag) {
                key += it;
            }
            else {
                result += it;
            }
        }

        return result;
    }
};