class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string result;
        
        for(auto it : words) {
            int sum = 0;
            
            for(auto ch : it) {
                sum += weights[ch - 'a'];
            }
            
            int temp = sum % 26;
            result.push_back(char('z' - temp));
        }
        
        return result;
    }
};