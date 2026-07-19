class Solution {
public:
    string smallestSubsequence(string s) {
        int n = s.size();
        vector<int> last(26);

        for(int i = 0; i < n; i++) {
            last[s[i] - 'a'] = i;
        }    

        vector<bool> inStack(26, false);
        string result;

        for(int i = 0; i < n; i++) {
            char it = s[i];

            if(inStack[it - 'a']) {
                continue;
            }    

            while(!result.empty() && result.back() > it && last[result.back() - 'a'] > i) {
                inStack[result.back() - 'a'] = false;
                result.pop_back();
            }

            result.push_back(it);
            inStack[it - 'a'] = true;
        }

        return result;
    }
};