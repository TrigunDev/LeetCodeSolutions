class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n = gain.size();
        int current = 0, result = 0;

        for(int i = 0; i < n; i++) {
            current += gain[i];

            if(current > result) {
                result = current;
            }   
        }

        return result;
    }
};