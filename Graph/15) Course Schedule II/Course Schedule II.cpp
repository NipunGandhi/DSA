class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        queue<int> q;
        vector<vector<int>> adL(numCourses);  
        vector<int> freq(numCourses,0);
        int cnt = 0;

        for(auto i: prerequisites){
            adL[i[1]].push_back(i[0]);
            freq[i[0]]++;
        }

        for(int i=0; i<numCourses;i++){
            if(freq[i] == 0){
                q.push(i);
            }
        }

        vector<int> ans;
        while(!q.empty()){
            int top = q.front();
            ans.push_back(top);
            q.pop();
            cnt++;

            for(auto i:adL[top]){
                freq[i]--;
                if(freq[i] == 0){
                    q.push(i);
                }
            }
        }
        if(numCourses != cnt) return {};
        return ans;
    }
};