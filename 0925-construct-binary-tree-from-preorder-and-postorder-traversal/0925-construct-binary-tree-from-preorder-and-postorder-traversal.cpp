class Solution {
public:
    unordered_map<int, int> postMap;
    TreeNode* help(vector<int>& preorder, int start, int end, int &idx){
        if(start > end) return nullptr;

        int rootvalue = preorder[idx++];
        TreeNode *root = new TreeNode(rootvalue);

        if(start == end) return root;


        int postIdx = postMap[preorder[idx]];

        root->left = help(preorder, start, postIdx, idx);
        root->right = help(preorder, postIdx+1, end-1, idx);
        return root;
    }

    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        postMap.clear();

        for(int i = 0; i < postorder.size(); ++i){
            postMap[postorder[i]] = i;
        }

        int idx = 0;
        return help(preorder, 0, preorder.size()-1, idx);
    }
};