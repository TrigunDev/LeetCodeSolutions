class Solution {
private:
    int dfs(int i, vector<int>& arr, int n, int d, vector<int>& dpp) {
        if(dpp[i] != -1) {
            return dpp[i];
        }    

        int best = 1;

        for(int next = i + 1; next <= min(n - 1, i + d); next++) {
            if(arr[next] >= arr[i]) {
                break;
            }   
            best = max(best, 1 + dfs(next, arr, n, d, dpp));
        }

        for(int next = i - 1; next >= max(0, i - d); next--) {
            if(arr[next] >= arr[i]) {
                break;
            }    
            best = max(best, 1 + dfs(next, arr, n, d, dpp));
        }

        return dpp[i] = best;
    }
   
public:
    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        vector<int> dpp(n, -1);
        int result = 1;

        for(int i = 0; i < n; i++) {
            result = max(result, dfs(i, arr, n, d, dpp));
        }

        return result;
    }
};