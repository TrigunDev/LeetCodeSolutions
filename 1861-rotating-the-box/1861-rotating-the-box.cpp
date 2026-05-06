class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int m = boxGrid.size(), n = boxGrid[0].size();

        for(int i = 0; i < m; i++) {
            int temp = n - 1;

            for(int j = n - 1; j >= 0; j--) {
                if(boxGrid[i][j] == '*') {
                    temp = j - 1;
                } 
                else if(boxGrid[i][j] == '#') {
                    swap(boxGrid[i][j], boxGrid[i][temp]);
                    temp--;
                }
            }
        }

        vector<vector<char>> result(n, vector<char>(m));

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                result[j][m-1-i] = boxGrid[i][j];
            }
        }

        return result;
    }
};