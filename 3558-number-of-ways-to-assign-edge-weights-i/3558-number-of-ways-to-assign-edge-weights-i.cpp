class Solution {
public:
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>> g(n+2);
        long long inf = 1000000007;
        int result = -1;

        for(auto it : edges) {
            g[min(it[0], it[1])].push_back(max(it[0], it[1])); 
        }

        queue<int> q{{1}};

        while(!q.empty()) {
            for(int j = q.size(); j; j--) {
                int i = q.front(); 
                q.pop();

                for(auto it : g[i]) {
                    q.push(it);
                }    
            }

            result = result == -1 ? 0 : !result ? 1 : (result*2) % inf;
        }

        return result;
    }
};