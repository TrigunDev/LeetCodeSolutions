class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        st.push(0);

        for(auto it : s) {
            if(it == '(') {
                st.push(0);
            } 
            else {
                int current = st.top();
                st.pop();
                st.top() += max(1, 2*current);
            }
        }

        return st.top();
    }
};