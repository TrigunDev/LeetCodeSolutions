class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> distance(m, vector<int>(n, INT_MAX));
        deque<pair<int, int>> dq;
        distance[0][0] = grid[0][0];
        dq.push_front({0, 0});
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        while(dq.empty() == false) {
            auto [x, y] = dq.front();
            dq.pop_front();

            if(x == m - 1 && y == n - 1) {
                return distance[x][y] < health;
            }    

            for(int k = 0; k < 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];

                if(nx < 0 || nx >= m || ny < 0 || ny >= n) {
                    continue;
                }    

                int w = grid[nx][ny];

                if(distance[x][y] + w < distance[nx][ny]) {
                    distance[nx][ny] = distance[x][y] + w;

                    if(w == 0) {
                        dq.push_front({nx, ny});
                    }    
                    else {
                        dq.push_back({nx, ny});
                    }    
                }
            }
        }

        return distance[m-1][n-1] < health;
    }
};