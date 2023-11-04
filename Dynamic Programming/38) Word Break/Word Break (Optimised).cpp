class Solution {
public:
    unordered_map<string, bool> umap;

    bool wordBreak(string s, vector<string>& wordDict) {
        if(s.size() == 0) return true;
        if(umap.find(s) != umap.end()) return umap[s];

        for(auto word: wordDict){
            if(word.size() <= s.size()){
                string partA = s.substr(0, word.size());
                if(partA == word){
                    string partB = s.substr(word.size());
                    if(wordBreak(partB, wordDict)) return umap[s] = true;
                }
            }
        }

        return umap[s] = false;
    }
};