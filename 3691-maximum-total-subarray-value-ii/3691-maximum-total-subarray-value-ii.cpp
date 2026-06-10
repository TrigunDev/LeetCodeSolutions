class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int n = nums.size();
        
        auto countGreaterOrEqual = [&](int threshold) {
            long long lessCount = 0;
            deque<int> minDeque, maxDeque;
            int leftIndex = 0;

            for(int rightIndex = 0; rightIndex < n; rightIndex++) {
                while(!maxDeque.empty() && nums[maxDeque.back()] <= nums[rightIndex]) {
                    maxDeque.pop_back();
                }
                while(!minDeque.empty() && nums[minDeque.back()] >= nums[rightIndex]) {
                    minDeque.pop_back();
                }

                maxDeque.push_back(rightIndex);
                minDeque.push_back(rightIndex);
                
                while(!maxDeque.empty() && !minDeque.empty() && nums[maxDeque.front()] - nums[minDeque.front()] >= threshold) {
                    leftIndex++;

                    if(maxDeque.front() < leftIndex) {
                        maxDeque.pop_front();
                    }    
                    if(minDeque.front() < leftIndex) {
                        minDeque.pop_front();
                    }    
                }

                lessCount += (rightIndex - leftIndex + 1);
            }

            long long totalSubarrays = (long long)n * (n + 1) / 2;

            return totalSubarrays - lessCount;
        };
        
        int lowThreshold = 0, highThreshold = 1e9, optimalThreshold = 0;
        
        while(lowThreshold <= highThreshold) {
            int midThreshold = lowThreshold + (highThreshold - lowThreshold) / 2;

            if(countGreaterOrEqual(midThreshold) >= k) {
                optimalThreshold = midThreshold;
                lowThreshold = midThreshold + 1;
            } 
            else {
                highThreshold = midThreshold - 1;
            }
        }
        
        int maxLog = 0;

        while((1 << maxLog) <= n) {
            maxLog++;
        }
        
        vector<vector<int>> sparseMax(n, vector<int>(maxLog));
        vector<vector<int>> sparseMin(n, vector<int>(maxLog));
        vector<int> logLookup(n + 1, 0);
        
        for(int i = 2; i <= n; i++) {
            logLookup[i] = logLookup[i/2] + 1;
        }
        
        for(int i = 0; i < n; i++) {
            sparseMax[i][0] = nums[i];
            sparseMin[i][0] = nums[i];
        }
        
        for(int j = 1; j < maxLog; j++) {
            for(int i = 0; i + (1 << j) <= n; i++) {
                sparseMax[i][j] = max(sparseMax[i][j - 1], sparseMax[i + (1 << (j - 1))][j - 1]);
                sparseMin[i][j] = min(sparseMin[i][j - 1], sparseMin[i + (1 << (j - 1))][j - 1]);
            }
        }
        
        auto queryMax = [&](int l, int r) {
            int j = logLookup[r-l+1];

            return max(sparseMax[l][j], sparseMax[r - (1 << j) + 1][j]);
        };
        
        auto queryMin = [&](int l, int r) {
            int j = logLookup[r-l+1];

            return min(sparseMin[l][j], sparseMin[r - (1 << j) + 1][j]);
        };
        
        long long result = 0, selectedCount = 0;
        deque<int> finalMinDeque, finalMaxDeque;
        int currentLeft = 0, strictThreshold = optimalThreshold + 1;
        
        for(int rightIndex = 0; rightIndex < n; rightIndex++) {
            while(!finalMaxDeque.empty() && nums[finalMaxDeque.back()] <= nums[rightIndex]) {
                finalMaxDeque.pop_back();
            }
            while(!finalMinDeque.empty() && nums[finalMinDeque.back()] >= nums[rightIndex]) {
                finalMinDeque.pop_back();
            }

            finalMaxDeque.push_back(rightIndex);
            finalMinDeque.push_back(rightIndex);
            
            while(!finalMaxDeque.empty() && !finalMinDeque.empty() && nums[finalMaxDeque.front()] - nums[finalMinDeque.front()] >= strictThreshold) {
                currentLeft++;

                if(finalMaxDeque.front() < currentLeft) {
                    finalMaxDeque.pop_front();
                }    
                if(finalMinDeque.front() < currentLeft) {
                    finalMinDeque.pop_front();
                }    
            }
            
            for(int l = 0; l < currentLeft; l++) {
                result += queryMax(l, rightIndex) - queryMin(l, rightIndex);
                selectedCount++;
            }
        }
        
        result += (long long)(k - selectedCount) * optimalThreshold;

        return result;
    }
};