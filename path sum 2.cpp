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
    void BFS(TreeNode* root, int targetSum, vector<int>&path, vector<vector<int>>&ans ){
        if(!root) return ;

        path.push_back(root->val);
        targetSum-=root->val;

        if(!root->left && !root->right && targetSum == 0){
            ans.push_back(path);
        }else{
            BFS(root->left,targetSum,path,ans);
            BFS(root->right,targetSum,path,ans);
        }
        path.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>ans;
        vector<int>path;
        BFS(root,targetSum,path,ans);
        return ans;

    }
};
