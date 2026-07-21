class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.size();
        int previous = 0, current = 0, total = 0, best = 0;
        int i = 0;

        while(i < n) {
            if(s[i] == '0') {
                previous++;
                i++;
            } 
            else {
                while(i < n && s[i] == '1') {
                    total++;
                    i++;
                }

                while(i < n && s[i] == '0') {
                    current++;
                    i++;
                }

                if(previous && current) {
                    best = max(best, previous + current);
                }    

                previous = current;
                current = 0;
            }
        }

        int result = total + best;

        return result;
    }
};