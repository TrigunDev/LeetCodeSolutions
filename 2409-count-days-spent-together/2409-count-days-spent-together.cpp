class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        vector<int> days = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        auto convert = [&](string s) {
            int n = stoi(s.substr(0, 2));
            int result = stoi(s.substr(3, 2));

            for(int i = 0; i < n-1; i++) {
                result += days[i];
            }

            return result;
        };

        int con1 = max(convert(arriveAlice), convert(arriveBob));
        int con2 = min(convert(leaveAlice), convert(leaveBob));
        int finalResult = max(0, con2-con1+1);

        return finalResult;
    }
};