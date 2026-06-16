class Solution {
public:
    string processStr(string s) {
        int n = s.length();
        string result;

        for(int i = 0; i < n; i++) {
            char it = s[i];

            if(it == '*') {
                if(result.length() != 0) {
                    result.pop_back();
                }
            } 
            else if(it == '#') {
                result += result;
            }
            else if(it == '%') {
                reverse(result.begin(), result.end());
            } 
            else if(it >= 'a' && it <= 'z') {
                result.push_back(it);
            }
        }

        return result;
    }
};