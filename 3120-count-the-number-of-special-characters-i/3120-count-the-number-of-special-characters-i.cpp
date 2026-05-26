class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_set<char> s;

        for(auto it : word) {
            s.insert(it);
        }

        int count = 0;

        for(char ch = 'a'; ch <= 'z'; ch++) {
            if(s.count(ch) && s.count(toupper(ch))) {
                count++;
            }
        }

        return count;
    }
};