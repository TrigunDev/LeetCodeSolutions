class Solution {
public:
    int numberOfSpecialChars(string word) {
        int n = word.size();
        vector<int> lower(26, -1);
        vector<int> upper(26, -1);

        for(int i = 0; i < n; i++) {
            char ch = word[i];

            if(islower(ch)) {
                lower[ch - 'a'] = i;
            }
            else {
                int index = ch - 'A';

                if(upper[index] == -1) {
                    upper[index] = i;
                }
            }
        }

        int result = 0;

        for(int i = 0; i < 26; i++) {
            if(lower[i] != -1 && upper[i] != -1 && lower[i] < upper[i]) {
                result++;
            }
        }

        return result;
    }
};