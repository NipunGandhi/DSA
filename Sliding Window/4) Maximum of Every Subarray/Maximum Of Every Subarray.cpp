class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        int i = 0, j = 0;
        deque<int> dq;  

        while (j < nums.size()) {
            // If deque is empty then we will insert first element
            if(dq.empty()) dq.push_front(nums[j]);

            // If front element is smaller that nums[j] then we will empty the list
            // And then insert the element
            else if(dq.front() < nums[j]){
                while(!dq.empty()){
                    dq.pop_front();
                }
                dq.push_front(nums[j]);
            } else {
                // If front element is larger that nums[j] then we will traverse
                // And pop the elements that are smaller than nums[j] 
                // because they will never be used 
                // and then insert the element
                while(!dq.empty() && nums[j] > dq.back()){
                    dq.pop_back();
                }
                dq.push_back(nums[j]);
            }
    
            if (j - i + 1 == k) {
                int element = dq.front();
                ans.push_back(element);
                
                // Changing the window 
                if(element == nums[i]){
                    dq.pop_front();
                }
                i++;
            }

            j++;
        }

        return ans;
    }
};
