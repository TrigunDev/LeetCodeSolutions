class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration,
    vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n = landStartTime.size(), m = waterStartTime.size();
        int result = INT_MAX;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                int landFinish = landStartTime[i] + landDuration[i];
                int tempLand = max(landFinish, waterStartTime[j]) + waterDuration[j];
                int waterFinish = waterStartTime[j] + waterDuration[j];
                int tempWater = max(waterFinish, landStartTime[i]) + landDuration[i];
                result = min({result, tempLand, tempWater});
            }
        }

        return result;
    }
};