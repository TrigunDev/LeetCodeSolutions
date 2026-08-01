class Solution {
private:
    long long countPermutations(vector<int>& count, long long limit) {
        int n = 0;

        for(auto it : count) {
            n += it;
        }    

        long long ways = 1;

        for(int ch = 0; ch < 26; ch++) {
            for(int i = 1; i <= count[ch]; i++) {
                ways = (ways * (n - count[ch] + i)) / i;

                if(ways > limit) {
                    return limit + 1;
                }
            }

            n -= count[ch];
        }

        return ways;
    }

    string kthPermutation(vector<int>& count, int k) {
        int n = 0;

        for(auto it : count) {
            n += it;
        }    

        if(n == 0) {
            return "";
        }    
        
        for(int ch = 0; ch < 26; ch++) {
            if(count[ch] == 0) {
                continue;
            }    

            count[ch]--;
            long long ways = countPermutations(count, k);

            if(k < ways) {
                return string(1, char('a' + ch)) + kthPermutation(count, k);
            }

            k -= ways;
            count[ch]++;
        }

        return "";
    }

    string reverseString(string s) {
        reverse(s.begin(), s.end());
        return s;
    }

public:
    string smallestPalindrome(string s, int k) {
        int n = s.size();
        vector<int> count(26, 0);

        for(int i = 0; i < n / 2; i++) {
            count[s[i] - 'a']++;
        }

        if(k > countPermutations(count, k)) {
            return "";
        }

        string result = kthPermutation(count, (long long)k-1);

        if(n % 2 == 0) {
            return result + reverseString(result);
        }

        return result + s[n/2] + reverseString(result);
    }
};