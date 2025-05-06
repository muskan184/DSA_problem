class Solution {
public:
    int countPaths(TreeNode* node, long long currSum, int targetSum) {
        if (!node) return 0;

        int count = 0;
        currSum += node->val;

        if (currSum == targetSum) count++;

        count += countPaths(node->left, currSum, targetSum);
        count += countPaths(node->right, currSum, targetSum);

        return count;
    }

    int pathSum(TreeNode* root, int targetSum) {
        if (!root) return 0;

        int fromRoot = countPaths(root, 0, targetSum);
        int fromLeft = pathSum(root->left, targetSum);
        int fromRight = pathSum(root->right, targetSum);

        return fromRoot + fromLeft + fromRight;
    }
};
