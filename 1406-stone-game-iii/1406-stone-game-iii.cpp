class Solution {
private:
    int solve(int index, vector<int> &stoneValue, vector<int> &dpp){
        if(index >= stoneValue.size()) {
            return 0;
        }    

        if(dpp[index] != -1) {
            return dpp[index];
        }    

        int result = -1e9, n = stoneValue.size(), sum = 0;

        for(int i = index; i < n; i++) {
            if(i-index+1 > 3) {
                break;
            }

            sum += stoneValue[i];
            result = max(result, sum - solve(i+1, stoneValue, dpp));
        }

        return dpp[index] = result;
    }

public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();

        int total = accumulate(stoneValue.begin(), stoneValue.end(), 0);

        vector<int> dpp(n+1, -1);
        int diff = solve(0, stoneValue, dpp);
        int alice = (diff+total) / 2;
        int bob = total - alice;

        if(alice > bob) {
            return "Alice";
        }    
        else if(bob > alice) {
            return "Bob";
        }    

        return "Tie";
    }
};