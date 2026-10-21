class Solution {
public:
    int minOperations(string s) {
        int n = s.size();

        if(is_sorted(s.begin(), s.end())) {
            return 0;
        }    
        if(n == 2) {
            return -1;
        }    

        char minn = *min_element(s.begin(), s.end());
        char maxx = *max_element(s.begin(), s.end());

        if(s[0] == minn || s[n-1] == maxx) {
            return 1;
        }    

        for(int i = 1; i < n-1; i++) {
            if(s[i] == minn || s[i] == maxx) {
                return 2;
            }    
        }

        return 3;
    }
};