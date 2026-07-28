class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.size();
        int mid = n / 2;

        sort(begin(s), begin(s) + mid);

        for(int i = 0; i < mid; i++) {
            s[n-1-i] = s[i];
        }

        return s;
    }
};