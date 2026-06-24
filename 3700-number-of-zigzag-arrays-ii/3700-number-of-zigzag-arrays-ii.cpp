class Solution {
private:
    static const long long MOD = 1000000007;
    vector<vector<long long>> func(vector<vector<long long>> &A, vector<vector<long long>> &B) {
        int n = A.size();
        vector<vector<long long>> C(n, vector<long long>(n, 0));

        for(int i = 0; i < n; i++) {
            for(int k = 0; k < n; k++) {
                if(A[i][k] == 0) {
                    continue;
                }    

                long long temp = A[i][k];

                for(int j = 0; j < n; j++) {
                    if(B[k][j] == 0) {
                        continue;
                    }                        

                    C[i][j] = (C[i][j] + temp * B[k][j]) % MOD;
                }
            }
        }

        return C;
    }

    vector<vector<long long>> solve(vector<vector<long long>> base, long long exp) {
        int n = base.size();
        vector<vector<long long>> result(n, vector<long long>(n, 0));

        for(int i = 0; i < n; i++) {
            result[i][i] = 1;
        }

        while(exp) {
            if(exp & 1) {
                result = func(base, result);
            }

            base = func(base, base);
            exp >>= 1;
        }

        return result;
    }

public:
    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;
        int S = 2 * m;
        vector<vector<long long>> T(S, vector<long long>(S, 0));

        for(int v = 0; v < m; v++) {
            for(int u = 0; u < v; u++) {
                T[v][m+u] = 1;
            }
        }

        for(int v = 0; v < m; v++) {
            for(int u = v + 1; u < m; u++) {
                T[m+v][u] = 1;
            }
        }

        vector<long long> state(S, 0);

        for(int v = 0; v < m; v++) {
            state[v] = v;               
            state[m+v] = m - 1 - v;  
        }

        vector<vector<long long>> P = solve(T, n-2);

        vector<long long> finalState(S, 0);

        for(int i = 0; i < S; i++) {
            long long value = 0;
            for(int j = 0; j < S; j++) {
                value = (value + P[i][j] * state[j]) % MOD;
            }
            finalState[i] = value;
        }

        long long result = 0;

        for(auto it : finalState) {
            result = (result + it) % MOD;
        }

        return (int)result;
    }
};