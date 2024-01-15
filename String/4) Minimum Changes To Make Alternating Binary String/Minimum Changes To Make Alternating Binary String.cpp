class Solution{
public:
    int solve(string &s, string &s1)
    {
        int count = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] != s1[i])
                count++;
        }
        return count;
    }

    int minOperations(string s)
    {
        int size = s.size();
        string s1 = "", s2 = "";
        for (int i = 0; i < size; i++)
            s1.push_back(i % 2 == 0 ? '0' : '1');
        for (int i = 0; i < size; i++)
            s2.push_back(i % 2 == 1 ? '0' : '1');
        return min(solve(s1, s), solve(s2, s));
    }
};