class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);

        for(auto it : edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<bool> visited(n, false);
        int result = 0;

        for(int i = 0; i < n; i++) {
            if(visited[i]) {
                continue;
            }    

            queue<int> q;
            q.push(i);
            visited[i] = true;

            int nodes = 0, edgeCount = 0; 

            while(q.empty() == false) {
                int u = q.front();
                q.pop();
                nodes++;
                edgeCount += adj[u].size();

                for(auto it : adj[u]) {
                    if(!visited[it]) {
                        visited[it] = true;
                        q.push(it);
                    }
                }
            }

            edgeCount /= 2;

            if(edgeCount == nodes * (nodes-1) / 2) {
                result++;
            }    
        }

        return result;
    }
};