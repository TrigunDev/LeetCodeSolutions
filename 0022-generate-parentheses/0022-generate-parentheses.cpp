class Solution {
private:
    void solve(int open, int close, int n, string s, vector<string> &result) {
        if(open == close && (open+close) == 2*n) {
            result.push_back(s); 
            return; 
        }

        if(open < n) {
            solve(open+1, close, n, s + '(', result); 
        }    
        if(close < open) {
            solve(open, close+1, n, s + ')', result); 
        }    
    }

public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        solve(0, 0, n, "", result);

        return result;
    }
};