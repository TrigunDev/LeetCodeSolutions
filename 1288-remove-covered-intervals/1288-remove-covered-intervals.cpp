class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        int result = n;
        sort(intervals.begin(), intervals.end());
        int i = 0, j = 1;

        while(i < n && j < n) {
            if(intervals[i][0] == intervals[j][0]) {
                result--;
                i = j;
            }
            else if(intervals[i][0] < intervals[j][0] && intervals[i][1] >= intervals[j][1]) {
                result--;
            }
            else {
                i = j;
            }

            j++;
        }

        return result;
    }
};