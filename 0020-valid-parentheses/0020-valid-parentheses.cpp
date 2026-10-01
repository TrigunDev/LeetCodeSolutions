class Solution {
private:
    bool isMatched(char open, char close) {
        if((open == '(' && close == ')') || (open == '[' && close == ']') ||
           (open == '{' && close == '}')) {
            return true;
           }    
        else {
            return false;
        }    
    }
   
public:
    bool isValid(string s) {
        int n = s.size();
        stack<char> st;
    
        for(int i = 0; i < n; i++) {
            if(s[i] == '(' || s[i] == '[' || s[i] == '{') {
                st.push(s[i]);
            }    
            else {
                if(st.empty()) {
                    return false;
                }    
        
                char ch = st.top();
                st.pop();
        
                if(!isMatched(ch, s[i])) {
                    return false;
                }    
            }
        }

        return st.empty();
    }
};