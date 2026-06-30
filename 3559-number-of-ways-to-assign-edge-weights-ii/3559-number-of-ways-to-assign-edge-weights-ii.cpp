class Solution {
private:
    long long solve(long long a, long long b) {
        long long result = 1;

        while(b > 0) {
            if(b & 1) {
                result = (result * a) % MOD;
            }

            a = (a * a) % MOD;
            b >>= 1;
        }

        return result;
    }

    int func(int u, int v, vector<int>& depth, vector<vector<int>>& up) {
        if(depth[u] < depth[v]) { 
            swap(u, v);
        }

        int diff = depth[u] - depth[v];
        
        for(int j = LOG - 1; j >= 0; j--) {
            if(diff & (1 << j)) {
                u = up[u][j];
            }
        }
       
        if(u == v) {
            return u;
        }    
        
        for(int j = LOG - 1; j >= 0; j--) {
            if(up[u][j] != up[v][j]) {
                u = up[u][j];
                v = up[v][j];
            }
        }

        return up[u][0];
    }

    void dfs(int node, int parent, vector<vector<int>>& adj, vector<int>& depth, vector<vector<int>>& up) {
        up[node][0] = parent;

        for(int j = 1; j < LOG; j++) {
            up[node][j] = up[up[node][j - 1]][j - 1];
        }

        for(auto it : adj[node]) {
            if(it == parent) {
                continue;
            }    

            depth[it] = depth[node] + 1;
            dfs(it, node, adj, depth, up);
        }
    }

public:
    static const int MOD = 1e9 + 7;
    int LOG;

    vector<int> assignEdgeWeights(vector<vector<int>>& edges,vector<vector<int>>& queries) {
        int n = edges.size() + 1;
        LOG = 1;

        while((1 << LOG) <= n) {
            LOG++;
        }    

        vector<vector<int>> adj(n + 1);

        for(auto it : edges) {
            int u = it[0], v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> depth(n+1, 0);
        vector<vector<int>> up(n+1, vector<int>(LOG, 0));
        dfs(1, 0, adj, depth, up);
        vector<int> result;

        for(auto it : queries) {
            int u = it[0], v = it[1];
            int L = func(u, v, depth, up);
            long long dist = depth[u] + depth[v] - 2LL * depth[L];

            if(dist == 0) {
                result.push_back(0);
            } 
            else {
                result.push_back(solve(2, dist-1));
            }
        }

        return result;
    }
};