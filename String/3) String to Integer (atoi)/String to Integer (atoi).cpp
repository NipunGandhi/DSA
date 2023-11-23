class Solution {
public:    
    int myAtoi(string s) {
        long long number = 0;
        bool isPositive = true;
        bool empty = true;

        for(int i = 0; i < s.size(); i++){
            char c = s[i];
            if(c == ' ' && empty) continue;
            else if(c == '+' && empty) {
                empty = false;
                continue;
            }
            else if(c == '-' && empty){
                isPositive = false;
                empty = false;
                continue;
            } 
            else if(c - '0' >= 0 && c - '0' <= 9){
                number *= 10;
                number += c - '0';
                empty = false;
                if(!isPositive && number > 2147483648) return number = -2147483648;
                if(isPositive && number > 2147483647) return number = 2147483647;
            }  else {
                break;
            }
        }

        if(!isPositive && number < 2147483648) return number *= -1;
        return number;
    }
};