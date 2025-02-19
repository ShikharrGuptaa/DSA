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
    priority_queue<int> maxHeap;
    
    void inOrder(TreeNode* root, int k){
        if(!root) return;

        inOrder(root->left, k);

        if(maxHeap.size() < k) maxHeap.push(root->val);
        else if(maxHeap.size() == k){
            if(root->val < maxHeap.top()){
                maxHeap.pop();
                maxHeap.push(root->val);
            }
        }
        inOrder(root->right, k);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        
        while(!maxHeap.empty()) maxHeap.pop();

        inOrder(root, k);
        return maxHeap.top();
    }
};