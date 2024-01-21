class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> umap;
        unordered_set<int> uniqueOccurrences;

        for (int num : arr) {
            umap[num]++;
        }

        for (auto& entry : umap) {
            if (!uniqueOccurrences.insert(entry.second).second) {
                return false;
            }
        }

        return true;
    }
};