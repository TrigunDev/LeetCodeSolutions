class Solution {
private:
    bool check(long long mid, vector<vector<pair<int, int>>> &adj, vector<int> &topo, vector<bool> &online, long long k, int n) {
        long long INF = 1e18;
        vector<long long> distance(n, INF);
        distance[0] = 0;

        for(auto it : topo) {
            if(distance[it] == INF) {
                continue;
            }    

            if(it != 0 && it != n-1 && !online[it]) {
                continue;
            }    

            for(auto &[v, w] : adj[it]) {
                if(w < mid) {
                    continue;
                }    
                if(v != n-1 && !online[v]) {
                    continue;
                }    

                distance[v] = min(distance[v], distance[it] + w);
            }
        }

        return distance[n-1] <= k;
    }

public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size();
        vector<vector<pair<int, int>>> adj(n);
        vector<int> indegree(n, 0);
        int maxx = 0;

        for(auto it : edges) {
            int u = it[0], v = it[1], w = it[2];
            adj[u].push_back({v, w});
            indegree[v]++;
            maxx = max(maxx, w);
        }

        queue<int> q;

        for(int i = 0; i < n; i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }    
        }

        vector<int> topo;

        while(q.empty() == false) {
            int u = q.front();
            q.pop();
            topo.push_back(u);

            for(auto &[v, w] : adj[u]) {
                if(--indegree[v] == 0) {
                    q.push(v);
                }    
            }
        }

        long long low = 0, high = maxx;
        int result = -1;

        while(low <= high) {
            long long mid = (low + high) / 2;

            if(check(mid, adj, topo, online, k, n)) {
                result = mid;
                low = mid + 1;
            } 
            else {
                high = mid - 1;
            }
        }

        return result;
    }
};