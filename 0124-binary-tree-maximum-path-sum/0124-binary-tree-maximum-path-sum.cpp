class Solution {
private:
    int help(TreeNode* root, int &maxi){
        if(!root) return 0;
        int left = max(0, help(root->left, maxi));
        int right = max(0, help(root->right, maxi));
        maxi = max(maxi, left + right + root->val);

        return max(left, right) + root->val;
    }
public:
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        help(root, maxi);
        return  maxi;
    }
};