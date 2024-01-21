class Solution{
public:
    vector<vector<int>> findWinners(vector<vector<int>> &matches)
    {
        set<int> element;
        unordered_map<int, int> indegree;
        vector<int> zeroLoss, oneLoss;

        for (int i = 0; i < matches.size(); i++)
        {
            element.insert(matches[i][0]);
            element.insert(matches[i][1]);
            indegree[matches[i][1]]++;
        }

        for (auto val : element)
        {
            if (indegree[val] == 0)
            {
                zeroLoss.push_back(val);
            }
            else if (indegree[val] == 1)
            {
                oneLoss.push_back(val);
            }
        }

        return {zeroLoss, oneLoss};
    }
};