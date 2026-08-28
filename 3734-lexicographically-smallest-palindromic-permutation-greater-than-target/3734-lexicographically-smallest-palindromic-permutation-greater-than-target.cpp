class Solution {
private:
    string func(int n, vector<int> freq, string current, char &mid, string& target) {
        for(int i = 25; i >= 0; i--) {
            while(freq[i]) {
                current += (char)('a' + i);
                freq[i]--;
            }
        }

        if(mid != '#') {
            string temp = current;
            current += mid;
            reverse(temp.begin(), temp.end());
            current.append(temp.begin(), temp.end());
        }
        else {
            string temp = current;
            reverse(temp.begin(), temp.end());
            current.append(temp.begin(), temp.end());
        }
      
        return current > target ? current : "";
    }

public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.size();
        vector<int> freq(26, 0);

        if(n == 1) {
            if(s > target) {
                return s;
            }    
            else {
                return "";
            }    
        }

        for(auto it : s) {
            freq[it-'a']++;
        }     

        char mid = '#';
        int oddCount = 0;

        for(int i = 0; i < 26; i++) {
            if(freq[i] % 2) {
                mid = (char)('a' + i);
                freq[i]--;
                oddCount++;
            }

            freq[i] /= 2; 

            if(oddCount >= 2) {
                return ""; 
            }    
        }

        n /= 2; 
        string result = "", prefix = "";

    
        for(int i = 0; i < n; i++) {
            string current = prefix;
            bool isThereAny = false;

            for(int j = 0; j < 26; j++) {
                if(freq[j]){
                    freq[j]--;
                    current += (char)('a' + j);
                    string isPos = func(n, freq, current, mid, target);

                    if(isPos != "") {
                        prefix = current;     
                        isThereAny = true;

                        if(result == "") {
                            result = isPos;
                        }    
                        else {
                            result = min(result, isPos); 
                        }    
                        break;
                    }

                    freq[j]++;
                    current.pop_back();
                }
            }

            if(!isThereAny) {
                return ""; 
            }    
        }

        return result; 
    }
};