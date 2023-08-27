class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        if (s.size() == 0) return false;
        sort(s.begin(), s.end());
        sort(g.begin(), g.end());
        int count = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] >= g[count]) {
                ++count;
                if (count >= g.size()) break;
            }
        }
        return count;
    }
};
