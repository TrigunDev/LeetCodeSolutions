class Solution {
public:
    int maxDepth(string s) {
        int current = 0, result = 0;

        for(auto it : s) {
            if(it == '(') {
                current++;
                result = max(result, current);
            }
            else if(it == ')') {
                current--;
            }
        }

        return result;
    }
};