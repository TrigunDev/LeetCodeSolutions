class Solution {
public:
    long long countCommas(long long n) {
        long long result = 0;

        for(long long i = 1000; i <= n; i *= 1000) {
            result += n-i+1;
        }

        return result;
    }
};