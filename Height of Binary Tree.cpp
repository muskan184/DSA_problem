class Solution {
  public:
    int height(Node* node) {
        // code here
        if(node == NULL) return -1;
        
        return 1+ max (height(node->left),height(node->right));
    }
};
