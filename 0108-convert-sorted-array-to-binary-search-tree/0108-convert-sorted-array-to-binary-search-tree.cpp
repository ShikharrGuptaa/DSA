class Solution {
private:
    TreeNode* Tree(vector<int> &nums, int start, int end){
        if(start > end) return nullptr;

        int idx = start + (end - start)/2;
        TreeNode* node = new TreeNode(nums[idx]);

        node->left = Tree(nums, start, idx-1);
        node->right = Tree(nums, idx+1, end);

        return node;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return Tree(nums, 0, nums.size()-1);
    }
};