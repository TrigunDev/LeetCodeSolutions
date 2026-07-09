class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> component(n);
        int id = 0;
        component[0] = id;

        for(int i = 1; i < n; i++) {
            if(nums[i] - nums[i-1] > maxDiff) {
                id++;
            }

            component[i] = id;
        }

        vector<bool> result;
        result.reserve(queries.size());

        for(auto it : queries) {
            result.push_back(component[it[0]] == component[it[1]]);
        }    

        return result;
    }
};