class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> operations;
        int targetIndex = 0; // Pointer for target array
        int currentNumber = 1; // Pointer for numbers 1 to n

        while (targetIndex < target.size()) {
            if (target[targetIndex] == currentNumber) {
                // If the current number in the target array matches the current number 1 to n
                // Push "Push" operation and move both pointers
                operations.push_back("Push");
                targetIndex++;
            } else {
                // If the numbers don't match, push "Push" followed by "Pop" operation
                // and only move the current number pointer
                operations.push_back("Push");
                operations.push_back("Pop");
            }
            currentNumber++;
        }

        return operations;
    }
};
