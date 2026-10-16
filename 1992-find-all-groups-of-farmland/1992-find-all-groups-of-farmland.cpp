class Solution {
private:
    void func(int r, int c, int &r2, int &c2, vector<vector<int>>& land, vector<vector<int>>& visited) {
        int m = land.size(), n = land[0].size();
        visited[r][c] = 1;
        int dp1[4] = {-1, 1, 0, 0}, dp2[4] = {0, 0, -1, 1};
        
        for(int i = 0; i < 4; i++) {
            int nr = dp1[i] + r, nc = dp2[i] + c; 
            
            if(nr >= 0 && nr < m && nc >= 0 && nc < n && land[nr][nc] == 1 && !visited[nr][nc]) {
                r2 = max(r2, nr);
                c2 = max(c2, nc);
                func(nr, nc, r2, c2, land, visited);
            }
        }
    }
    
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int m = land.size(), n = land[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));
        vector<vector<int>> result;
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(!visited[i][j] && land[i][j] == 1) {
                    int r2 = i, c2 = j;
                    func(i, j, r2, c2, land, visited);
                    result.push_back({i, j, r2, c2});
                }
            }
        }
        
        return result;
    }
};