class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        vector<int> freq(3, 0);
        int low = 0, result = 0;

        for(int right = 0; right < n; right++) {
            freq[s[right] - 'a']++;

            while(freq[0] && freq[1] && freq[2]) {
                result += (n - right);
                freq[s[low] - 'a']--;
                low++;
            }
        }

        return result;
    }
};