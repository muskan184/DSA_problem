class Solution {
  public:
    // Function to count the number of leaf nodes in a binary tree.
    int countLeaves(Node* root) {
        // write code here
        if(root == NULL) return 0;
        
        if(!root->left && !root->right) return 1;
        return ( countLeaves(root->left)+ countLeaves(root->right));
    }
};
