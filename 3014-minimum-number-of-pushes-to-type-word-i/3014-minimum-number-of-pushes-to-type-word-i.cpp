class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        int result = 0;

        while(n > 0) {
            result += n; 
            n -= 8;
        }

        return result;
    }
};