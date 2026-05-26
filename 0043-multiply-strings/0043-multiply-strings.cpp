class Solution {
public:
    string multiply(string num1, string num2) {
        int n = num1.size(), m = num2.size();

        if(num1[0] == '0' || num2[0] == '0') {
            return "0";
        }

        vector<int> num(n+m, 0);

        for(int i = n-1; i >= 0; i--) {
            for(int j = m-1; j >= 0; j--) {
                num[i+j+1] += (num1[i] - '0') * (num2[j] - '0');
                num[i+j] += num[i+j+1] / 10;
                num[i+j+1] %= 10;  
            }
        }
        
        int i = 0;

        while(num[i] == 0) {
            i++;
        }

        string result = "";

        while(i < num.size()) {
            result.push_back(num[i] + '0');
            i++;
        }

        return result;
    }
};