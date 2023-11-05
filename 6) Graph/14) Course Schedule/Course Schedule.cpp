class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        queue<int> q;
        vector<vector<int>> adL(numCourses);  
        vector<int> freq(numCourses,0);
        int cnt = 0;

        for(auto i: prerequisites){
            adL[i[0]].push_back(i[1]);
            freq[i[1]]++;
        }

        for(int i=0; i<numCourses;i++){
            if(freq[i] == 0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int top = q.front();
            cnt++;
            q.pop();

            for(auto i:adL[top]){
                freq[i]--;
                if(freq[i] == 0){
                    q.push(i);
                }
            }
        }
        return cnt == numCourses;
    }
};