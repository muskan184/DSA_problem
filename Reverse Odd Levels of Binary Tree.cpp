class Solution {
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        if (!root) return nullptr;

        queue<TreeNode*> q;
        q.push(root);
        int level = 0;

        while (!q.empty()) {
            int size = q.size();
            vector<TreeNode*> nodesAtLevel;

            for (int i = 0; i < size; ++i) {
                TreeNode* node = q.front(); q.pop();
                nodesAtLevel.push_back(node);

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            if (level % 2 == 1) {
                int i = 0, j = nodesAtLevel.size() - 1;
                while (i < j) {
                    swap(nodesAtLevel[i]->val, nodesAtLevel[j]->val);
                    i++;
                    j--;
                }
            }

            level++;
        }

        return root;
    }
};
