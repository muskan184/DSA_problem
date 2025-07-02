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
    int dfs (TreeNode* node,int maxSoFar){
        if(!node) return 0;

        int count =0;
        if(node->val >= maxSoFar){
            count=1;
        }
        maxSoFar=max(node->val,maxSoFar);
        count+=dfs(node->left,maxSoFar);
        count+=dfs(node->right,maxSoFar);

        return count;
    }
    int goodNodes(TreeNode* root) {
       return dfs(root,INT_MIN);
    }
};
