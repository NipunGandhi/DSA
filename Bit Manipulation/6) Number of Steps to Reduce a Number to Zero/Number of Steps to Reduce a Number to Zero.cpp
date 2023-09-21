class Solution {
public:
    int numberOfSteps(int num) {
        if(!num) return num;
        int count = -1;
        while(num){
            if(num & 1) count++;
            count++;
            num >>= 1;
        }
        return count;
    }
};