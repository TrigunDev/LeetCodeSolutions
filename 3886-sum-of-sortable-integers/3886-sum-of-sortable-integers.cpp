class Solution {
private:
    bool func(vector<int>& nums, int k) {
        int n = nums.size(), previous = 0;

        for(int i = 0; i < n; i += k) {
            int count = 0;
            int minn = nums[i], maxx = nums[i];

            for(int j = i; j < i+k-1; j++) {
                if(nums[j] > nums[j+1]) {
                    count++;
                }    

                minn = min(minn, nums[j+1]);
                maxx = max(maxx, nums[j+1]);
            }

            if(nums[i+k-1] > nums[i]) {
                count++;
            }    
            if(count > 1 || previous > minn) {
                return false;
            }    

            previous = maxx;
        }

        return true;
    }

public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size(), result = 0;

        for(int i = 1; i*i <= n; i++) {
            if(n % i == 0) {
                if(func(nums, i)) {
                    result += i;
                }    
                if(i*i != n && func(nums, n/i)) {
                    result += n/i;
                }    
            }
        }

        return result;
    }
};