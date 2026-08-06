class Solution {
private:
    void solve(int u, vector<vector<int>> &adj, vector<bool> &visited) {
        visited[u] = true;

        for(auto it : adj[u]) {
            if(visited[it]) {
                continue;
            }

            solve(it, adj, visited);
        }
    }

public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n);

        for(auto it : invocations) {
            int u = it[0], v = it[1];
            adj[u].push_back(v);
        }

        vector<bool> visited(n,false);
        solve(k, adj, visited);

        for(auto it : invocations) {
            int u = it[0], v = it[1];

            if(visited[u]) {
                continue;
            }    

            if(visited[v]) {
                vector<int> result;

                for(int i = 0; i < n; i++) {
                    result.push_back(i);
                }

                return result;
            }
        }

        vector<int> ans;

        for(int i = 0; i < n; i++) {
            if(!visited[i]) {
                ans.push_back(i);
            }    
        }

        return ans;
    }
};