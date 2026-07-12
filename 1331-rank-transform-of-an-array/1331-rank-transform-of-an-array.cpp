class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        vector<int> vec = arr;
        sort(vec.begin(), vec.end());
        vec.erase(unique(vec.begin(), vec.end()), vec.end());

        for(int i = 0; i < n; i++) {
            arr[i] = lower_bound(vec.begin(), vec.end(), arr[i]) - vec.begin() + 1;
        }

        return arr;
    }
};