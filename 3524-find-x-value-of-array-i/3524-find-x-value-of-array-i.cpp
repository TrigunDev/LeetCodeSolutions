class Solution { 
public: 
    vector<long long> resultArray(vector<int>& nums, int k) { 
        vector<long long> result(k, 0);
        vector<long long> current(k, 0);

        for(auto it : nums) {
            int temp = it % k;
            vector<long long> next(k, 0);
            next[temp] = 1;

            for(int i = 0; i < k; i++) {
                if(current[i] > 0) {
                    int nr = (int)((1LL*i*temp) % k);
                    next[nr] += current[i];
                }
            }

            for(int j = 0; j < k; j++) {
                result[j] += next[j];
            }

            current = next;
        }

        return result;
    } 
};