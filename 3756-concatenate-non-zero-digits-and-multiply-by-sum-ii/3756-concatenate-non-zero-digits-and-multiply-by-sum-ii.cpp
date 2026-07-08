class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size();
        long long mod = 1e9 + 7;
        vector<long long> power(n+1, 1);

        for(int i = 1; i <= n; i++) {
            power[i] = (power[i-1] * 10) % mod;
        }    

        vector<int> index(n+1, 0);
        vector<long long> value(n+1, 0);
        vector<long long> total(n+1, 0);
        int count = 0;

        for(int i = 0; i < n; i++) {
            int digit = s[i] - '0';

            if(digit != 0) {
                count++;
                value[count] = (value[count-1] * 10 + digit) % mod;
                total[count] = total[count-1] + digit;
            }

            index[i+1] = count;
        }

        vector<int> result;

        for(auto it : queries) {
            int l = it[0], r = it[1];
            int left = index[l], right = index[r + 1];
      
            if(left == right) { 
                result.push_back(0);
                continue;
            }

            int length = right-left;

            long long number =(value[right] - value[left] * power[length]) % mod;

            if(number < 0) {
                number += mod;
            }    

            long long sum = total[right] - total[left];
            result.push_back((number * sum) % mod);
        }

        return result;
    }
};