class Solution {
public:
    int trailingZeroes(int n) {
        int result = (n/5) + (n/(5*5)) + (n/(5*5*5)) + (n/(5*5*5*5)) + (n/(5*5*5*5*5));

        return result;
    }
};