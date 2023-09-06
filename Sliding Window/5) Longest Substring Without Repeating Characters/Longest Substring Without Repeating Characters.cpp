class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0; int number = 0;
        vector <int> freq (256,0);
        int j = 0;

        for(int i=0; i < s.size(); i++){
            if(freq[s[i]] == 0){
                freq[s[i]]++;
                number++;
            }
            
            else if(freq[s[i]] > 0){
                if(s[i] != s[j] || (s[i] == s[j] && i-j == 1)){
                    freq[s[j]]--;
                    i--;
                    number--;
                }
                j++;
            }

            ans = max(ans, number);
        }

        return ans;
    }
};