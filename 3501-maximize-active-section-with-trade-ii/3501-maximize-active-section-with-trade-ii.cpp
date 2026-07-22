class Solution {
public:
    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& queries) {
        int stringLength = s.size();
        int totalOnes = ranges::count(s, '1');
        vector<int> zeroStarts, zeroEnds;
        
        for(int i = 0; i < stringLength; ) {
            if(s[i] == '0') {
                int j = i;

                while(j < stringLength && s[j] == '0') {
                    j++;
                }

                zeroStarts.push_back(i); 
                zeroEnds.push_back(j-1);
                i = j;
            } 
            else {
                i++;
            }
        }

        int numZeroBlocks = zeroStarts.size();

        vector<int> adjacentZeroGains;

        for(int valleyIdx = 0; valleyIdx+1 < numZeroBlocks; valleyIdx++) {
            int leftBlockLen = zeroEnds[valleyIdx] - zeroStarts[valleyIdx] + 1;
            int rightBlockLen = zeroEnds[valleyIdx+1] - zeroStarts[valleyIdx+1] + 1;
            adjacentZeroGains.push_back(leftBlockLen + rightBlockLen);
        }

        int numGains = adjacentZeroGains.size();
        vector<vector<int>> sparseTable{adjacentZeroGains};

        for(int stepSize = 1; stepSize*2 <= numGains; stepSize *= 2) {
            auto& prevLevel = sparseTable.back();
            vector<int> nextLevel;
            nextLevel.reserve(prevLevel.size() - stepSize);

            for(int i = 0; i+stepSize < (int)prevLevel.size(); i++) {
                nextLevel.push_back(max(prevLevel[i], prevLevel[i+stepSize]));
            }
            sparseTable.push_back(move(nextLevel));
        }

        auto getMaxGainInRange = [&](int leftIdx, int rightIdx) {
            int logPower = bit_width(unsigned(rightIdx-leftIdx+1)) - 1;
            return max(sparseTable[logPower][leftIdx], sparseTable[logPower][rightIdx - (1 << logPower) + 1]);
        };

        auto calculateClippedGain = [&](int valleyIdx, int queryStart, int queryEnd) {
            int leftCut = max(0, queryStart - zeroStarts[valleyIdx]);
            int rightCut = max(0, zeroEnds[valleyIdx+1] - queryEnd);
            return adjacentZeroGains[valleyIdx] - leftCut - rightCut;
        };

        auto calculateMaxGainForQuery = [&](int queryStart, int queryEnd) {
            if(numZeroBlocks < 2) {
                return 0;
            }    
            
            int firstValidValley = ranges::lower_bound(zeroEnds, queryStart) - zeroEnds.begin(); 
            int lastValidValley = ranges::upper_bound(zeroStarts, queryEnd) - zeroStarts.begin() - 2; 
            
            if(firstValidValley > lastValidValley) {
                return 0;
            }     
            
            int maxClippedGain = max( calculateClippedGain(firstValidValley, queryStart, queryEnd), calculateClippedGain(lastValidValley, queryStart, queryEnd)
            );
            
            int maxInnerGain = 0;

            if(lastValidValley - firstValidValley >= 2) {
                maxInnerGain = getMaxGainInRange(firstValidValley+1, lastValidValley-1);
            }
            
            return max(maxClippedGain, maxInnerGain);
        };

        vector<int> results;
        results.reserve(queries.size());

        for(auto& q : queries) {
            results.push_back(totalOnes + calculateMaxGainForQuery(q[0], q[1]));
        }
        
        return results;
    }
};