class Solution {
private:
    int solve(vector<int>& lStart,vector<int>& lDuration,vector<int>& wStart,vector<int>& wDuration) {
        int minn = INT_MAX;

        for(int i = 0; i < lStart.size(); i++) {
            minn = min(minn, lStart[i] + lDuration[i]);
        }

        int result = INT_MAX;

        for(int i = 0; i < wStart.size(); i++) {
            result = min(result, max(minn, wStart[i]) + wDuration[i]);
        }

        return result;
    }

public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        return min(solve(landStartTime,landDuration,waterStartTime,waterDuration), solve(waterStartTime,waterDuration,landStartTime,landDuration));
    }
};