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
    TreeNode* insertBst(TreeNode* node, int key){
        if(!node) return new TreeNode(key);
        if(node->val >key)
        node->left =insertBst(node->left,key);
        else if(node->val<key)
        node->right=insertBst(node->right,key);
        return node;
    }

    void serialize(TreeNode* root, vector<int>& res){
        if(!root) return ;
        res.push_back(root->val);
        serialize(root->left,res);
        serialize(root->right,res);
    }
public:
    vector<TreeNode*> generateTrees(int n) {
      vector<int>v(n);
      for(int i=0;i<n;i++){
        v[i]=i+1;
      }  

      set<vector<int>>st;
      vector<TreeNode*>ans;

      do{
        TreeNode* root = new TreeNode(v[0]);
        for(int i=1;i<n;i++){
            root=insertBst(root,v[i]);
        }
        vector<int>t;
        serialize(root,t);
        if(st.find(t)==st.end()) {
            st.insert(t);
            ans.push_back(root);
        }
        }while(next_permutation(v.begin(),v.end()));
      return ans;
    }
};
