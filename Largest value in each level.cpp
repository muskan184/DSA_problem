class Solution
{
    public:
    void findMaxPerLevel(Node* root, int level, vector<int>& maxAtLevel) {
    if (!root) return;

    // If this level is seen first time
    if (level == maxAtLevel.size()) {
        maxAtLevel.push_back(root->data);
    } else {
        maxAtLevel[level] = max(maxAtLevel[level], root->data);
    }

    // Recur for left and right subtree
    findMaxPerLevel(root->left, level + 1, maxAtLevel);
    findMaxPerLevel(root->right, level + 1, maxAtLevel);
}

    vector<int> largestValues(Node* root)
    {
        //code here
         vector<int> maxAtLevel;
    findMaxPerLevel(root, 0, maxAtLevel);
    return maxAtLevel;
    }
};
