class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        int result = 0;
        vector<int> visited(n, 0);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 0});

        while(!pq.empty()) {
            int wt = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if(visited[node]) {
                continue;
            }    

            visited[node] = 1;
            result += wt;

           
            for(int i = 0; i < n; i++) {
                if(!visited[i]) {
                    int cost = abs(points[node][0] - points[i][0]) + abs(points[node][1] - points[i][1]);
                    pq.push({cost, i});
                }
            }
        }

        return result;
    }
};