class Solution {
public:
    int minimumPushes(string word) {
        vector<int> solve(26, 0);

        for(auto it : word) {
            solve[it-'a']++;
        }

        sort(solve.begin(), solve.end(), greater<int>());
        int result = 0;

        for(int i = 0; i < 26; i++) {
            if(solve[i] == 0) {
                break;
            }

            result += solve[i] * ((i/8) + 1);
        }

        return result;
    }
};