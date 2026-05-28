class Solution {
public:
    int climbStairs(int n) {
        if(n <= 3) {
            return n;
        }    

        int previous1 = 3, previous2 = 2, current = 0;

        for(int i = 3; i < n; i++) {
            current = previous1 + previous2;
            previous2 = previous1;
            previous1 = current;
        }

        return current;        
    }
};