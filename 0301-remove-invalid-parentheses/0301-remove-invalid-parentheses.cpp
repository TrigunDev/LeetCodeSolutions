class Solution {
    void solve(string s, int scanStart, int deleteStart, char open, char close, vector<string>& result) {
        int balance = 0;

        for(int i = scanStart; i < s.size(); i++) {
            if(s[i] == open) {
                balance++;
            } 
            else if(s[i] == close) {
                balance--;
            }
            if(balance >= 0) {
                continue;
            }

            for(int j = deleteStart; j <= i; j++) {
                if(s[j] == close && (j == deleteStart || s[j-1] != close)) {
                    solve(s.substr(0, j) + s.substr(j+1), i, j, open, close, result);
                }
            }

            return;
        }

        reverse(s.begin(), s.end());

        if(open == '(') {
            solve(s, 0, 0, ')', '(', result);
        } 
        else {
            result.push_back(s);
        }
    }

public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> result;
        solve(s, 0, 0, '(', ')', result);

        return result;
    }
};