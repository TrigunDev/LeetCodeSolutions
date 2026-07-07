class Solution {
public:
    long long sumAndMultiply(int n) {
        long long temp = 0, sum = 0;
        string s = to_string(n);

        for(auto it : s) {
            if(it != '0') {
                temp = temp * 10 + (it - '0');
            }

            sum += (it - '0');
        }

        long long result = temp * sum;

        return result;
    }
};