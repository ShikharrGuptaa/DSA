/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    unordered_map<int, int> inordermap;

    TreeNode* Tree(vector<int>& inorder, vector<int>& postorder, int start, int end, int &idx){
        if(start > end) return nullptr;

        int rootValue = postorder[idx--];// Getting the Node/Root right now
        TreeNode* node = new TreeNode(rootValue); // Creating new node
        int inIdx = inordermap[rootValue]; // Index for inOrder Map

        node->right = Tree(inorder, postorder, inIdx+1, end, idx);
        node->left = Tree(inorder, postorder, start, inIdx-1, idx);

        return node;
    }


public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        // Logging all inorder w map to find it in O(1)
        for(int i = 0; i < inorder.size(); ++i){
            inordermap[inorder[i]] = i;
        }
        int idx = inorder.size()-1;

        return Tree(inorder, postorder, 0, inorder.size()-1, idx);
    }
};