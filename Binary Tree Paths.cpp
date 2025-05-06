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
public:
    vector<string> binaryTreePaths(TreeNode* root) {
         vector<string> result;
        string path = "";
        dfs(root, path, result);
        return result;
    }

    void dfs(TreeNode* node, string path, vector<string>& result) {
        if (!node) return;

        if (!path.empty()) path += "->";
        path += to_string(node->val);

        if (!node->left && !node->right) {
            result.push_back(path);
            return;
        }
        dfs(node->left, path, result);
        dfs(node->right, path, result);
    }
};
