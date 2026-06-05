class Solution {
private:
    string digits;
    long long countMemo[16][3][11][11];
    long long wavinessMemo[16][3][11][11];
    bool visited[16][3][11][11];

    pair<long long, long long> result(int position, int tight, int lengthState, int previousSecond, int previousFirst) {
        if(position == digits.size()) {
            return {1, 0};
        }

        if(!tight && visited[position][lengthState][previousSecond + 1][previousFirst + 1]) {
            return {
                countMemo[position][lengthState][previousSecond + 1][previousFirst + 1],
                wavinessMemo[position][lengthState][previousSecond + 1][previousFirst + 1]
            };
        }

        int limit = tight ? digits[position] - '0' : 9;
        long long totalCount = 0;
        long long totalWaviness = 0;

        for(int digit = 0; digit <= limit; digit++) {
            int nextTight = tight && (digit == limit);

            if(lengthState == 0 && digit == 0) {
                auto child = result(position + 1, nextTight, 0, -1, -1);
                totalCount += child.first;
                totalWaviness += child.second;
            } 
            else {
                int nextLengthState;
                int nextPreviousSecond;
                int nextPreviousFirst;
                long long contribution = 0;

                if(lengthState == 0) {
                    nextLengthState = 1;
                    nextPreviousSecond = -1;
                    nextPreviousFirst = digit;
                } 
                else if(lengthState == 1) {
                    nextLengthState = 2;
                    nextPreviousSecond = previousFirst;
                    nextPreviousFirst = digit;
                } 
                else {
                    nextLengthState = 2;
                    nextPreviousSecond = previousFirst;
                    nextPreviousFirst = digit;

                    if((previousFirst > previousSecond && previousFirst > digit) ||
                        (previousFirst < previousSecond && previousFirst < digit)) {
                        contribution = 1;
                    }
                }

                auto child = result(position + 1, nextTight, nextLengthState, nextPreviousSecond, nextPreviousFirst);
                totalCount += child.first;
                totalWaviness += child.second + child.first * contribution;
            }
        }

        if(!tight) {
            visited[position][lengthState][previousSecond + 1][previousFirst + 1] = true;
            countMemo[position][lengthState][previousSecond + 1][previousFirst + 1] = totalCount;
            wavinessMemo[position][lengthState][previousSecond + 1][previousFirst + 1] = totalWaviness;
        }

        return {totalCount, totalWaviness};
    }

    long long func(long long limit) {
        if(limit <= 0) {
            return 0;
        }    

        digits = to_string(limit);
        memset(visited, 0, sizeof(visited));

        return result(0, 1, 0, -1, -1).second;
    }

public:    
    long long totalWaviness(long long num1, long long num2) {
        return func(num2) - func(num1 - 1);
    }
};