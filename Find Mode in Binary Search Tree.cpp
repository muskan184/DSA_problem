class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        vector<int> ans;
        TreeNode* prev = nullptr;
        int maxCount = 0, count = 0;

        function<void(TreeNode*)> inorder = [&](TreeNode* node) {
            if (!node) return;
            inorder(node->left);

            if (prev && prev->val == node->val) {
                count++;
            } else {
                count = 1;
            }

            if (count == maxCount) {
                ans.push_back(node->val);
            } else if (count > maxCount) {
                ans.clear();
                ans.push_back(node->val);
                maxCount = count;
            }

            prev = node;
            inorder(node->right);
        };

        inorder(root);
        return ans;
    }
};
