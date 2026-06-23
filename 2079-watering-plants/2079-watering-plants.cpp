class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int n = plants.size();
        int result = 0, current = capacity;

        for(int i = 0; i < n; i++) {
            if(current < plants[i]) {
                result += (2*i);
                current = capacity;
            }

            result++;
            current -= plants[i];
        }

        return result;
    }
};