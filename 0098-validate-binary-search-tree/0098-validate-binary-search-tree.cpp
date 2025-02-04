class Solution {
public:
    bool isValidBST(TreeNode* root, long minVal, long maxVal) {
        if (!root) return true;
        
        // The current node's value must be within the range (minVal, maxVal)
        if (root->val <= minVal || root->val >= maxVal) return false;

        // Recursively validate left and right subtrees
        return isValidBST(root->left, minVal, root->val) &&
               isValidBST(root->right, root->val, maxVal);
    }

    bool isValidBST(TreeNode* root) {
        return isValidBST(root, LONG_MIN, LONG_MAX);
    }
};