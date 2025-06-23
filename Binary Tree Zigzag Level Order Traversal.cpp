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
    void helper(TreeNode*root,int cur_level,vector<vector<int>>&ans){
        if(root == NULL) return;
        if(cur_level == ans.size()) ans.push_back({});
        ans[cur_level].push_back(root->val);
        helper(root->left,cur_level+1,ans); 
        helper(root->right,cur_level+1,ans); 
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        helper(root,0,ans);
        for(int i = 1;i<ans.size();i+=2)
            reverse(ans[i].begin(),ans[i].end());
        return ans;
    }
};
