class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.size();
        unordered_map<char, int> mpp;
        int i = 0, j = 0, result = 0;
        
        while(j < n) {
            mpp[s[j]]++;

            while(mpp[s[j]] > 2) {
                mpp[s[i]]--;
                i++;
            }

            result = max(result, j-i+1);
            j++;
        }

        return result;
    }
};