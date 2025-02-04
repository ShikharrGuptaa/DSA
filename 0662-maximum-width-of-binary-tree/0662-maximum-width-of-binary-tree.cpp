class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;

        queue<pair<TreeNode*, long long>> q; // (node, index)
        q.push({root, 0});

        int maxWidth = 0;
        
        while (!q.empty()) {
            int size = q.size();
            long long leftMost = q.front().second;
            long long rightMost = q.back().second;
            
            maxWidth = max(maxWidth, (int)(rightMost - leftMost + 1));

            for (int i = 0; i < size; i++) {
                auto [node, index] = q.front();
                q.pop();

                // Normalize indices to avoid overflow issues
                index -= leftMost;

                if (node->left) q.push({node->left, 2 * index + 1});
                if (node->right) q.push({node->right, 2 * index + 2});
            }
        }
        
        return maxWidth;
    }
};
