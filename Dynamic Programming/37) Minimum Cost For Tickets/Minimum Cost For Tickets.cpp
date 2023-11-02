class Solution {
public:
    int recursion(vector<int>& days, vector<int>& costs, int index, vector<int>& memo){
        if(index < 0) return 0;
        if(index == 0) return min({costs[0], costs[1], costs[2]});
        if(memo[index] != -1) return memo[index];
        
        int choice1 = costs[0] + recursion(days, costs, index - 1, memo);

        int i = index;
        while(i >= 0 && days[index] - days[i] < 7){
            i--;
        }

        int choice2 = costs[1] + recursion(days, costs, i, memo);
        
        i = index;
        while(i >= 0 && days[index] - days[i] < 30){
            i--;
        }

        int choice3 = costs[2] + recursion(days, costs, i, memo);
      
        return memo[index] = min({choice1, choice2, choice3});
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        // vector<int> memo (days.size(), -1);
        // return recursion(days, costs, days.size() - 1, memo);
        vector<int> memo (days.size(), 0);
        memo[0] = min({costs[0], costs[1], costs[2]});

        for(int i = 1; i < days.size(); i++){
            int choice1 = costs[0] + memo[i-1];

            int j = i;
            while(j >= 0 && days[i] - days[j] < 7){
                j--;
            }

            int choice2 = costs[1];
            if(j >= 0) choice2 += memo[j];
            
            j = i;
            while(j >= 0 && days[i] - days[j] < 30){
                j--;
            }
        
            int choice3 = costs[2];
            if(j >= 0) choice3 += memo[j];
        
            memo[i] = min({choice1, choice2, choice3});
        }
        return memo[days.size() - 1];
    }
};