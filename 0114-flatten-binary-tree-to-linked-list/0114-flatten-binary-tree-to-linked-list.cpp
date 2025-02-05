class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode* curr = root; // Current Node we're at
        // Iterating it until curr exists
        while(curr){
            // If Current->Left exists, so we'll do 
                // 1: Go to rightmost of that left
                // 2: Connect that rightmost to the right of the predecessor's(curr) right;
                // 3: Move Left subtree to right and pointing left subtree to NULLPTR
            if(curr->left){
                // Connecting like a thread, like we did in Morris Traversal
                TreeNode *prev = curr->left;
                // Going to rightmost
                while(prev->right) prev = prev->right;
                // Reached rightmost -> Connecting it to right of predecessor
                prev->right = curr->right;
                // Moving the left to right
                curr->right = curr->left;
                // Pointed the left to NULL
                curr->left = nullptr;
            }
            curr = curr->right;
        }
    }
};