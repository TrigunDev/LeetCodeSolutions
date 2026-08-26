class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        string result = "";

        for(int i = 0; i < n; i++) {
            int oneCount = 0;
            string current = "";

            for(int j = i; j < n; j++) {
                current += s[j];

                if(s[j] == '1') {
                    oneCount++;
                }    
                if(oneCount > k) {
                    break;
                }    
                if(oneCount == k) {
                    if(result == "" || current.size() < result.size() || (current.size() == result.size() && current < result)) {
                        result = current;
                    }
                }
            }
        }

        return result;
    }
};