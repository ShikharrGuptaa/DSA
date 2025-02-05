class Solution {
private:
    unordered_map<int, int> inorderIndex;
    int preIdx = 0;

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder, int left, int right) {
        if (left > right) return NULL;

        int rootValue = preorder[preIdx++];
        TreeNode* root = new TreeNode(rootValue);
        int inIdx = inorderIndex[rootValue];

        root->left = buildTree(preorder, inorder, left, inIdx - 1);
        root->right = buildTree(preorder, inorder, inIdx + 1, right);

        return root;
    }

public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<int> inorder = preorder;
        sort(inorder.begin(), inorder.end());

        for (int i = 0; i < inorder.size(); i++) {
            inorderIndex[inorder[i]] = i;
        }

        return buildTree(preorder, inorder, 0, inorder.size() - 1);
    }
};
