class NumArray {
public:
    vector<int> num;
    NumArray(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        if(num.size() == i) {
            num.push_back(nums[i]);
            cout<<num[i]<<endl;
        }
        i++;
        while(i<n){
            num.push_back(nums[i] + num[i-1]);
            cout<<num[i]<<endl;
            i++;
        }
    }
    
    int sumRange(int left, int right) {
        if(left == 0) return num[right];
        return num[right] - num[left-1];
    }
};