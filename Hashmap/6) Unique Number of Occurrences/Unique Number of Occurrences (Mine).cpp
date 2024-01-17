// Mine and looks better to me
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> umap;
        vector<int> vec(1001, -1001);
        for(auto i : arr){
            umap[i]++;
        }
        for(auto i : umap){
            int occurence = i.second;
            if(vec[occurence] != -1001) return false;
            vec[occurence] = occurence;
        }
        return true;
    }
};