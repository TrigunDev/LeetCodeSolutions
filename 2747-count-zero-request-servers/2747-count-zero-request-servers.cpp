class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        int length = logs.size(), m = queries.size();

        sort(logs.begin(), logs.end(), [&](vector<int> &vec1, vector<int> &vec2) {
            return vec1[1] < vec2[1]; 
        }); 

        vector<pair<int, int>> vec; 

        for(int i = 0; i < m; i++) {
            vec.push_back({queries[i], i}); 
        }

        sort(vec.begin(), vec.end()); 
        unordered_map<int, int> mpp; 
        vector<int> result(m, 0); 
        int left = 0, right = 0; 

        for(int i = 0; i < m; i++) {
            int start = vec[i].first - x; 
            int end = vec[i].first; 

            while(right < length && logs[right][1] <= end) {
                mpp[logs[right][0]]++; 
                right++; 
            }

            while(left < right && logs[left][1] < start) {
                mpp[logs[left][0]]--; 

                if(mpp[logs[left][0]] == 0) {
                    mpp.erase(logs[left][0]); 
                }

                left++; 
            }

            result[vec[i].second] = n - mpp.size(); 
        }

        return result; 
    }
};