// Time Complexity: O(N) where N is the number of nodes in the tree
// Space Complexity: O(M): where M is the maximum number in the tree at any level
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(!root)  return {};
        vector<vector<int>> ans;
        queue<Node*> q;
        q.push(root); 
            while(!q.empty()) {
            int n = q.size(); 
            vector<int> level;
            for(int i = 0; i < n; i++){
                Node* node = q.front();
                q.pop();
                level.push_back(node->val);
                for(auto n : node->children) q.push(n); 
            }
                 ans.push_back(level);
        }
        return ans;
    }
};
