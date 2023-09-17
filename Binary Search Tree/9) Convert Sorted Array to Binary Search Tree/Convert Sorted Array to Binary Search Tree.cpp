class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return bst(nums,0, nums.size()-1);
    }

    TreeNode* bst(vector<int>& nums, int left, int right){
        if(left>right) return NULL;
        int mid = (left+right)/2;
        TreeNode* node = new TreeNode(nums[mid]);
        node->left = bst(nums, left, mid-1);
        node->right = bst(nums, mid+1, right);
        return node;
    }
};