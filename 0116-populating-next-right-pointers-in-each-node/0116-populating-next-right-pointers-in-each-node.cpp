class Solution {
private:
    void mark(Node *root){
        if(!root || (!root->left && !root->right)) return;
        
        root->left->next = root->right;
        
        if(root->next) root->right->next = root->next->left;
        
        mark(root->left);
        mark(root->right);
    }
public:
    Node* connect(Node* root) {
        mark(root);
        return root;
    }
};