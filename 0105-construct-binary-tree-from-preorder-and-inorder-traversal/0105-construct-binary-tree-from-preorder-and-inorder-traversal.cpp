class Solution {
private:
    unordered_map<int, int> inorderMap;
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int start, int end, int& idx) {
        if (start > end) return nullptr;

        int rootValue = preorder[idx++];
        TreeNode* node = new TreeNode(rootValue);

        int inIdx = inorderMap[rootValue]; 

        node->left = build(preorder, inorder, start, inIdx - 1, idx);
        // Here we didn't manually increased idx+1 as we are using idx by reference and so it first completes making left subtree complete then comes back to right call, until all that left subtreee is already formed.
        
        node->right = build(preorder, inorder, inIdx + 1, end, idx);

        return node;
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        inorderMap.clear();
        for (int i = 0; i < inorder.size(); ++i) {
            inorderMap[inorder[i]] = i; // Precompute inorder indices
        }

        int idx = 0; // Preorder index
        return build(preorder, inorder, 0, inorder.size() - 1, idx);
    }
};
