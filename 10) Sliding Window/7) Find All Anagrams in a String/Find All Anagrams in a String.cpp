class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans; int K = p.size();
        unordered_map <char, int> umap;
        int left = 0;
        for(auto i:p) umap[i]++;
        int count = umap.size();

        for(int right = 0; right<s.size(); right++){
            char c = s[right];
            if(umap.find(c) != umap.end()){
                umap[c]--;
                if(umap[c] == 0) count--;
            }

            if(right - left + 1 == K){
                if(count == 0) ans.push_back(right - p.size() + 1);
                char c1 = s[left];
                if(umap.find(c1) != umap.end()){
                    umap[c1]++;
                    if(umap[c1] == 1) count++;
                }
                left++;
            }
        }

        return ans;
    }
};