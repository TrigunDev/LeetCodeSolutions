class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int result = 0;

        for(int i = num1; i <= num2; i++) {
            string s = to_string(i);
            int n = s.size();

            for(int j = 1; j + 1 < n; j++) {
                if((s[j] > s[j-1] && s[j] > s[j+1]) || (s[j] < s[j-1] && s[j] < s[j+1])) {
                    result++;
                }
            }
        }

        return result;
    }
};