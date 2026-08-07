class Solution {
private:
    long long gcd(long long a,long long b) {
        if(a == 0) {
            return b;
        }

        return gcd(b % a, a);
    }

    bool check(string a, string b) {
        if(a.length() > b.length()) {
            return true;
        }

        if(a.length() < b.length()) {
            return false;
        }

        return a.compare(b) > 0;
    }

public:
    string smallestNumber(string num, long long t) {
        int n = num.length();
        vector<long> remind(n+1);
        remind[0] = t;
        int end = n;

        for(int i = 0; i < n; i++) {
            if(num[i] == '0') {
                end = i + 1;
                break;
            }

            remind[i+1] = remind[i] / gcd(remind[i], num[i] - '0');
        }

        if(end == n && remind[n] == 1) {
            return num;
        }    

        for(int i = end - 1; i >= 0; i--) {
            while(num[i] < '9') {
                long tt = remind[i];
                num[i]++;
                tt /= gcd(tt, num[i] - '0');

                for(int j = n - 1; j > i; j--) {
                    for(int k = 9; k > 0; k--) {
                        if(tt % k == 0) {
                            tt /= k;
                            num[j] = '0' + k;
                            break;
                        }
                    }
                }

                if(tt == 1) {
                    return num;
                }    
            }
        }

        string result;

        for(int i = 9; t > 1 && i > 1; i--) {
            while(t % i == 0) {
                result += to_string(i);
                t /= i;
            }
        }

        if(t != 1) {
            return "-1";
        }

        reverse(result.begin(), result.end());

        if(check(result, num)) {
            return result;
        }

        if(result.length() == num.length()) {
            return "1" + result;
        }    

        int difference = num.length() - result.length();

        if(check(string(difference, '1') + result, num)) {
            return string(difference, '1') + result;
        }

        return string(difference + 1, '1') + result;
    }
};