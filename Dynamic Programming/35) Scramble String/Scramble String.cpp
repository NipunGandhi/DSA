class Solution {
public:
    unordered_map<string, bool> umap;
    
    bool isScramble(string s1, string s2) {
        if(s1 == s2) return true;
        if(s1.size() == 2) return s1[0] == s2[1] && s2[0] == s1[1];
        if(s1.size() != s2.size()) return false;
       
        string key = s1 + " " + s2;
        if(umap.find(key) != umap.end()) return umap[key];
       
        int length = s1.size();
        
        // Optional thing (Added because we know this shit is constant in time)
        // And this can prevent us from doing excess recursive calls
        vector<int> count(26, 0);
        for (int k = 0; k < length; k++) {
            count[s1[k] - 'a']++;
            count[s2[k] - 'a']--;
        }
        for (int k = 0; k < 26; k++) {
            if (count[k] != 0) {
                return  umap[key] = false;
            }
        }

        for(int k = 1; k < length; k++){
            if(isScramble(s1.substr(0, k), s2.substr(0, k)) && isScramble(s1.substr(k), s2.substr(k))){
                return  umap[key] = true;
            }
            if (isScramble(s1.substr(0, k), s2.substr(length - k)) && isScramble(s1.substr(k), s2.substr(0, length - k))){
                return  umap[key] = true;
            } 
        }
        
        return umap[key] = false;
    }
};