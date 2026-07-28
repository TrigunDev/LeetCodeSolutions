class Solution {
public:
    int maxProduct(int n) {
        int maxValue = n % 10, secMaxValue = -1;
        n /= 10;
        
        while(n > 0) {
            int digit = n % 10;

            if(digit < maxValue) {
                if(digit > secMaxValue) {
                    secMaxValue = digit;
                }
            } 
            else if(digit == maxValue) {
                secMaxValue = maxValue;
            }
            else {
                secMaxValue = maxValue;
                maxValue = digit;
            }

            n /= 10;
        }

        int result = maxValue * secMaxValue;

        return result;
    }
};