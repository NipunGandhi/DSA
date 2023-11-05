class Solution {
public:
    bool possible(vector<int>& bloomDay, int m, int k, int bloom){
        int count = k;
        int n = bloomDay.size();

        for(int i = 0; i < n; i++){
            if(m == 0) break;
            if(bloom >= bloomDay[i]){
                count--;
                if(count == 0){
                    count = k;
                    m--;
                }
            } else {
                count = k;
            }
        }
        cout<< m << " " << bloom << endl;
        return m == 0;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long high = *max_element(bloomDay.begin(), bloomDay.end());
        long long low = 1, mid = 0;
        long long ans = INT_MAX;

        while(low <= high){
            mid = (low+high)/2;
            bool bloom = possible(bloomDay, m, k, mid);
            if(bloom){
                high = mid - 1;
                ans = min(ans, mid);
            } else{
                low = mid + 1;
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};