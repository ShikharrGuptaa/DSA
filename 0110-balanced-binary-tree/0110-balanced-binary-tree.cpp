class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return help(root) != -1;
    }
    
    int help(TreeNode* node) {
        if (!node) return 0;

        int left = help(node->left);
        if (left == -1) return -1;
        int right = help(node->right);
        if (right == -1) return -1;

        if (abs(left - right) > 1) return -1;
        
        return max(left, right) + 1;
    }
};