class Solution {
public:
    char processStr(string s, long long k) {
        int n = s.size();
        long long length = 0;

        for(auto it : s) {
            if(it == '*') {
                length = max(0LL, length-1);
            }
            else if(it == '#') {
                length *= 2;
            }
            else if(it != '%') {
                length++;
            }
        }

        if(k >= length) {
            return '.';
        }    

        for(int i = n-1; i >= 0; i--) {
            char it = s[i];

            if(it == '*') {
                length++;
            }
            else if(it == '#') {
                long long half = length / 2;

                if(k >= half) {
                    k -= half;
                }

                length = half;
            }
            else if(it == '%') {
                k = length-1-k;
            }
            else {
                if(k == length-1) {
                    return it;
                }

                length--;
            }
        }

        return '.';
    }
};