class Solution {
public:
    bool sumGame(string num) {
        double n = num.length();
        double result = 0;

        for(int i = 0; i < n; i++) {
            double count;

            if(i < n/2) {
                count = 1;
            } 
            else {
                count = -1;
            }

            double value;

            if(num[i] == '?') {
                value = 4.5;
            } 
            else {
                value = num[i] - '0';
            }

            result += count * value;
        }

        if(result != 0.0) {
            return true;
        } 
        else {
            return false;
        }
    }
};