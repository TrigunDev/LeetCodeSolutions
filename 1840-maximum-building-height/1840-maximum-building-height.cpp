class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        restrictions.push_back({1, 0});
        restrictions.push_back({n, n-1});
        sort(restrictions.begin(), restrictions.end());
        int m = restrictions.size();

        for(int i = 1; i < m; i++) {
            restrictions[i][1] = min(restrictions[i][1], restrictions[i-1][1] + restrictions[i][0] - restrictions[i-1][0]);
        }    

        for(int i = m-2; i >= 0; i--) {
            restrictions[i][1] = min(restrictions[i][1], restrictions[i+1][1] + restrictions[i+1][0] - restrictions[i][0]);
        }    

        int result = 0;

        for(int i = 0; i+1 < m; i++) {
            int temp = restrictions[i+1][0] - restrictions[i][0];
            result = max(result, (restrictions[i][1] + restrictions[i+1][1] + temp) / 2);
        }

        return result;
    }
};