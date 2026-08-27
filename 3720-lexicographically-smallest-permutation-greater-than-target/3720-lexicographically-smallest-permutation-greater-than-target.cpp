class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = target.size();
        int count[26] = {};

        for(auto it : s) {
            count[it-'a']++;
        }

        for(auto it : target) {
            count[it-'a']--;
        }

        for(int i = n-1; i >= 0; i--) {
            int current = target[i] - 'a';
            count[current]++;
            bool ok = true;

            for(int j = 0; j < 26; j++) {
                if(count[j] < 0) {
                    ok = false;
                    break;
                }
            }

            if(!ok) {
                continue;
            }    

            int next = -1;

            for(int j = current+1; j < 26; j++) {
                if(count[j] > 0) {
                    next = j;
                    break;
                }
            }

            if(next == -1) {
                continue;
            }    

            count[next]--;
            string result = target.substr(0, i);
            result += char('a'+next);

            for(int j = 0; j < 26; j++) {
                result.append(count[j], char('a'+j));
            }

            return result;
        }

        return "";
    }
};