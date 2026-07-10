class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<pair<int, int>> newNum(n);

        for(int i = 0; i < n; i++) {
            newNum[i] = {nums[i], i};
        }

        sort(newNum.begin(), newNum.end());

        vector<int> get(n);

        for(int i = 0; i < n; i++) {
            get[newNum[i].second] = i;
        }    

        vector<vector<int>> s(n, vector<int>(18));

        int r = 0;

        for(int i = 0; i < n; i++) {
            if(r < i) {
                r = i;
            }

            while(r+1 < n && newNum[r+1].first - newNum[r].first <= maxDiff && newNum[r+1].first - newNum[i].first <= maxDiff) {
                r++;
            }

            s[i][0] = r;
        }

        for(int j = 1; j < 18; j++) {
            for(int i = 0; i < n; i++) {
                s[i][j] = s[s[i][j-1]][j-1];
            }
        }        

        vector<int> result(queries.size(), -1);

        for(int i = 0; i < queries.size(); i++) {
            int a = get[queries[i][0]];
            int b = get[queries[i][1]];

            if(a > b) {
                swap(a, b);
            }    
            if(a == b) { 
                result[i] = 0; 
                continue; 
            }

            int current = a, steps = 0;

            for(int j = 17; j >= 0; j--) {
                if(s[current][j] < b) { 
                    current = s[current][j]; 
                    steps += (1 << j); 
                }
            }

            result[i] = (s[current][0] >= b) ? steps + 1 : -1;
        }

        return result;
    }
};