class Solution {
private:
    int find(vector<int>& inorder, int start, int end, int elem){
        for(int i = start; i <= end; ++i){
            if(inorder[i] == elem) return i;
        }

        return end-1;
    }

    TreeNode* Tree(vector<int>& preorder, vector<int>& inorder, int start, int end, int idx){
        if(start > end) return nullptr;

        TreeNode* node = new TreeNode(preorder[idx]);
        int pre = find(inorder, start, end, preorder[idx]); // Found the index at inorder's vector
        // On left of pre, we'll have left elements and on right vice versa

        node->left = Tree(preorder, inorder, start, pre-1, idx+1); // idx+1 because NLR so after node that's wy just after idx we get left
        node->right = Tree(preorder, inorder, pre+1, end, idx+(pre-start)+1);

        return node;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return Tree(preorder, inorder, 0, inorder.size()-1, 0);
    }
};