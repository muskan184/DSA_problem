class Solution {
  public:
    int getSize(Node* node) {
        // code here
        if(node == NULL) return 0;
        return (1+getSize(node->left)+getSize(node->right));
    }
};
