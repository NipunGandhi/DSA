class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> set;
        int count = 0;
        int left = 0;

        for(int right = 0; right < s.size(); right++){
            char c = s[right];
            while (set.find(c) != set.end()) {
                set.erase(s[left]);
                left++;
            }
            set.insert(s[right]);
            count = max(count,right-left+1);
        }

        return count;
    }
};