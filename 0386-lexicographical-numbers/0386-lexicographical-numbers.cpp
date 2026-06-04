class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> result;
        int count = 1;

        for(int i = 0; i < n; i++) {
            result.push_back(count);

            if(count * 10 <= n) {
                count *= 10;  
            } 
            else {
                if(count >= n) {
                    count /= 10;
                }
                count++;

                while(count % 10 == 0) {
                    count /= 10;  
                }    
            }
        }

        return result;
    }
};