class Solution {
    public int maximumGap(int[] nums) {
              int maxi = 0;
        if (nums.length == 0) {
            return 0;
        }
     Arrays.sort(nums);
        int n = nums.length;
        for (int i = 0; i < n - 1; i++) {
            int sub = nums[i + 1] - nums[i];
            if (sub > maxi) {
                maxi = sub;
            }
        }
        return maxi;
        
    }
}
