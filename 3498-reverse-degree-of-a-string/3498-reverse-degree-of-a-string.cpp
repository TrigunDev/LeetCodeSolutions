class Solution {
public:
    int reverseDegree(string s) {
        int n = s.size();
        int result = 0;

        for(int i = 0; i < n; i++) {
            result += (i+1) * (26-(s[i]-'a'));
        }
     
        return result;
        
    }
};