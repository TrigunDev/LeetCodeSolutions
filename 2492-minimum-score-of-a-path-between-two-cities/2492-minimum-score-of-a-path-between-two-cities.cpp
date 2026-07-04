class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n + 1);

        for(auto it : roads) {
            int u = it[0], v = it[1], w = it[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        vector<bool> visited(n+1, false);
        queue<int> q;
        q.push(1);
        visited[1] = true;
        int result = INT_MAX;

        while(q.empty() == false) {
            int node = q.front();
            q.pop();

            for(auto &[neighbour, it] : adj[node]) {
                result = min(result, it);

                if(visited[neighbour] == false) {
                    visited[neighbour] = true;
                    q.push(neighbour);
                }
            }
        }

        return result;
    }
};