class Solution {
private:
    pair<int, int> help(TreeNode* root){
        if(!root) return {0, 0};

        pair<int, int> left = help(root->left);
        pair<int, int> right = help(root->right);

        int op1 = left.first;
        int op2 = right.first;
        int op3 = left.second + right.second;

        pair<int, int> ans;

        ans.first = max({op1, op2, op3});
        ans.second = max(left.second, right.second) + 1;

        return ans;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        return help(root).first;
    }
};