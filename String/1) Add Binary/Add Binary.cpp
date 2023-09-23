class Solution {
public:
    string addBinary(string a, string b) {
        string ans = "";
        bool carry = false;
        while(a != "" & b != ""){
            if(a[a.size()-1] == '1' && b[b.size()-1] == '1'){
                if(!carry){
                    ans = '0' + ans;
                } 
                else {
                    ans = '1' + ans;
                }
                carry = true;
            } 
            else if(a[a.size()-1] == '0' && b[b.size()-1] == '0') {
                if(!carry){
                    ans = '0' + ans;
                } 
                else {
                    ans = '1' + ans;
                }
                carry = false;
            }
            else {
                if(!carry){
                    ans = '1' + ans;
                } 
                else {
                    ans = '0' + ans;
                }
            }
            a.pop_back();
            b.pop_back();
        }
        if(a != "") {
            if(carry){
                for(int i=a.size()-1; i>=0; i--){
                    if(a[i] == '0'){
                        a[i] = '1';
                        carry = false;
                        break;
                    } else {
                        a[i] = '0';
                    }
                }
            }
            ans = a + ans;
        }
        else if(b != ""){
            if(carry){
                for(int i=b.size()-1; i>=0; i--){
                    if(b[i] == '0'){
                        b[i] = '1';
                        carry = false;
                        break;
                    } else {
                        b[i] = '0';
                    }
                }
            }
            ans = b + ans;
        } 
        return carry ? '1'+ ans : ans;
    }
};