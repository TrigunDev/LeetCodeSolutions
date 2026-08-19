class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, unordered_set<int>> mpp;

        for(auto it : reservedSeats) {
            int row = it[0], seat = it[1];

            if(seat >= 2 && seat <= 5) {
                mpp[row].insert(0);
            }
            if(seat >= 4 && seat <= 7) {
                mpp[row].insert(1);
            }
            if(seat >= 6 && seat <= 9) {
                mpp[row].insert(2);
            }
        }

        int result = 2*n;

        for(auto& [row, groups] : mpp) {
            if(groups.size() == 3) {
                result -= 2;
            } 
            else {
                result -= 1;
            }
        }

        return result;
    }
};