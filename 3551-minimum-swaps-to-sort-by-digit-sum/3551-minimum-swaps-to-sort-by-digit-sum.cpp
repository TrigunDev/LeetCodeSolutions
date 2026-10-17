class Solution {
private:
    int func(int n) {
        int answer = 0;

        while(n > 0) {
            answer += n % 10;
            n /= 10;
        }

        return answer;
    }

public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        map<int, vector<int>> mpp;

        for(int i = 0; i < n; i++) {
            int sum = func(nums[i]);
            mpp[sum].push_back(nums[i]);
        }

        vector<int> arr;

        for(auto it : mpp) {
            sort(it.second.begin(), it.second.end());

            for(auto element : it.second) {
                arr.push_back(element);
            }
        }

        map<int,int> freq;

        for(int i = 0; i < n; i++) {
            freq[arr[i]] = i;
        }

        int result = 0;
        vector<bool> passed(n, false);

        for(int i = 0; i < n; i++) {
            if(passed[i]) {
                continue;
            }    

            int currentIndex = i, count = 0;

            while(!passed[currentIndex]) {
                passed[currentIndex] = true;
                currentIndex = freq[nums[currentIndex]];
                count++;
            }

            result += count - 1;
        }

        return result;
    }
};