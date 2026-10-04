class Solution {  
public:
    bool checkValidString(string s) {
       int minOpen = 0, maxOpen = 0;

        for(auto it : s) {
            if(it == '(') {
                minOpen++; 
                maxOpen++;
            } 
            else if(it == ')') {
                minOpen--; 
                maxOpen--; 
            } 
            else if(it == '*') {
                minOpen--; 
                maxOpen++;
            }

            if(minOpen < 0) {
                minOpen = 0; 
            }    
            if(maxOpen < 0) {
                return false;
            }    
        }
        
        return minOpen == 0;
    }
};