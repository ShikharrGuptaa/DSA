class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> result;
        if (!root) return result;

        // Map: Horizontal distance -> Level -> Sorted Set of Node Values
        map<int, map<int, multiset<int>>> Nodes;

        // Queue: Node, {Horizontal Distance, Level}
        queue<pair<TreeNode*, pair<int, int>>> q;
        q.push({root, {0, 0}});

        while (!q.empty()) {
            auto [node, pos] = q.front();
            q.pop();

            int dist = pos.first, lvl = pos.second;
            Nodes[dist][lvl].insert(node->val);  // Maintain sorted order at each level

            if (node->left) q.push({node->left, {dist - 1, lvl + 1}});
            if (node->right) q.push({node->right, {dist + 1, lvl + 1}});
        }

        // Convert map values to result vector
        for (auto& [dist, levels] : Nodes) {
            vector<int> col;
            for (auto& [lvl, values] : levels) {
                col.insert(col.end(), values.begin(), values.end());  // Merge sorted values
            }
            result.push_back(col);
        }

        return result;
    }
};