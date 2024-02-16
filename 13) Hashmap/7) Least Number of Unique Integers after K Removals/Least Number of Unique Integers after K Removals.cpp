class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> freq; 
    
        for(int i = 0; i < arr.size(); i++){
            freq[arr[i]]++;
        }

        int totalElements = freq.size();

        priority_queue<int, vector<int>, greater<int>> pq;

        for(auto val: freq) pq.push(val.second);

        while(k > 0){
            int top = pq.top();
            if(top > k) return totalElements;
            else if(top == k) return totalElements - 1;
            else {
                totalElements--;
                k -= top;
            }
            pq.pop();
        }

        return totalElements;
    }
};