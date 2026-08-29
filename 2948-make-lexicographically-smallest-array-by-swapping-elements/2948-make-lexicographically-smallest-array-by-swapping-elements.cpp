class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<pair<int,int>> vec; 

        for(int i = 0; i < n ; i++) {
            vec.push_back({nums[i] , i});
        }    
        
        sort(vec.begin(), vec.end());
        vector<vector<int>> value, index ;
        value.push_back({vec[0].first});
        index.push_back({vec[0].second});
        int j = 0, previous = vec[0].first ;

        for(int i = 1; i < n; i++) {
            int value1 = vec[i].first ;
           
            if(abs(value1-previous) <= limit) {
                value[j].push_back(value1);
                index[j].push_back(vec[i].second);

            }
            else {
                j++;
                value.push_back({value1});
                index.push_back({vec[i].second});

            }
            previous = vec[i].first;
        }

        for(auto &it: index) {
            sort(it.begin(), it.end());
        }
 
        vector<int> result(n, 0);

        for(int i = 0; i < value.size(); i++) {
            for(int j = 0; j < value[i].size(); j++) {
                result[index[i][j]] = value[i][j];
            }
        }

        return result; 

    }
};