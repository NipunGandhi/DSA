class Solution {
  public:
    int getLastDigit(string a, string b) {
        if(b.size() == 1 && b[0] - '0' == 0) return 1;
        int carry = 0;
        
        for(int i = 0; i < b.size(); i++){
            int key = b[i] - '0';
            int sum = key + (carry * 10);
            carry = sum % 4;
        }
        
        if(carry == 0) carry = 4;
        
        int n = a.size();
        int key2 = a[n-1] - '0';
        
        int w = pow(key2, carry);
        return w % 10;
    }
};