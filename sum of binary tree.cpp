class Solution {
  public:
    int sumBT(Node* root) {
        // code here
        if(root == NULL) return 0;
        
        return (root->data+sumBT(root->left)+sumBT(root->right));
    }
};
