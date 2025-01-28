class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int n=nums.size();
        // sort(nums.begin(),nums.end());
        int distance=0;
        for(int i=0;i<n;i++){
            int diff = abs(nums[i]-nums[(i+1)%n]);
            distance = max(distance,diff);
            }
        
        return distance;
    }
};
