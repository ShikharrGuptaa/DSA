class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (!root) return result;
        queue<TreeNode*> q;

        bool leftToRight = true;

        q.push(root);
        q.push(NULL);
        vector<int>temp;
        while(!q.empty()){
            TreeNode *frontNode = q.front();
            q.pop();

            if(!frontNode){
                if(leftToRight){
                    leftToRight = !leftToRight;
                }
                else{
                    reverse(temp.begin(), temp.end());
                    leftToRight = !leftToRight;
                }
                result.push_back(temp);
                temp.clear();
                if (!q.empty()) {
                    q.push(NULL);
                }
            }
            else{
                temp.push_back(frontNode->val);
                if(frontNode->left) q.push(frontNode->left);
                if(frontNode->right) q.push(frontNode->right);
            }

        }

        return result;
    }
};