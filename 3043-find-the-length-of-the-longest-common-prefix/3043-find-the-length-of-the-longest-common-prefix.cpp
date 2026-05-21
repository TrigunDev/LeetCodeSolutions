class Solution {
private:
    int digits(int it) {
        int count = 0;

        while(it > 0) {
            count++;
            it /= 10;
        }

        return count;
    }

public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> st;

        for(auto it : arr1) {
            while(it > 0) {
                st.insert(it);
                it /= 10;
            }
        }

        int result = 0;
        
        for(auto it : arr2) {
            int len = digits(it);

            while(it > 0) {
                if(st.count(it)) {
                    result = max(result, len);
                    break;
                }

                it /= 10;
                len--;
            }
        }

        return result;
    }
};