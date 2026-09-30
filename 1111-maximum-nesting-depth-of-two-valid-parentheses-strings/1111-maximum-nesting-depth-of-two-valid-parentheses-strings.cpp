class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int depth = 0;
        vector<int> result;

        for(auto it : seq) {
            if(it == '(') {
                depth++;
                result.push_back(depth%2);
            } 
            else {
                result.push_back(depth%2);
                depth--;
            }
        }

        return result;
    }
};