class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();
    vector<int> isFlipped(n, 0);  // Mark flip positions
    int flipCount = 0, flip = 0;  // `flip` tracks ongoing flips

    for (int i = 0; i < n; i++) {
        // Remove expired flips (out of the k-window)
        if (i >= k) flip ^= isFlipped[i - k];

        // If the effective bit is 0, flip is needed
        if (flip == nums[i]) {
            if (i + k > n) return -1; // If flipping goes out of bounds
            isFlipped[i] = 1;  // Mark the start of a flip
            flip ^= 1;  // Toggle the flip status
            flipCount++;
        }
    }
    return flipCount;
}
};
