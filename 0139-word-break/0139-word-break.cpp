class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        set<string> dictionary;

        for(auto it : wordDict) {
            dictionary.insert(it);
        }    
        
        vector<bool> dpp(n+1, false);
        dpp[0] = true; 
        
       
        for(int i = 0; i < n; i++) {
           
            for(int j = i; j >= 0; j--) {
                string current = s.substr(j, i-j+1); 
                
                if(dictionary.find(current) != dictionary.end()) {
                    dpp[i+1] = dpp[i+1] || dpp[j]; 
                }    
                if(dpp[i+1]) {
                    break;
                }    
            }
        }
        
        return dpp[n];
    }
};