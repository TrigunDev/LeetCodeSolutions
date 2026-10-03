class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        int left = 0, right = 0, result = 0;

        for(auto it : s) {
            if(it == '(') {
                left++;
            }    
            else {
                right++;
            }

            if(left == right) {
                result = max(result, 2*right);
            }    
            else if(right > left) {
                left = 0, right = 0;
            }    
        }

        left = right = 0;

        for(int i = n-1; i >= 0; i--) {
            if(s[i] == '(') {
                left++;
            }    
            else {
                right++;
            }   

            if(left == right) {
                result = max(result, 2*left);
            }    
            else if(left > right) {
                left = right = 0;
            }    
        }

        return result;
    }
};