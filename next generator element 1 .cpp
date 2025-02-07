class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();
        unordered_map<int,int> nge(n);
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            int it=nums2[i];
            while(!st.empty() && st.top()<=nums2[i]){
                st.pop();
            }
            if(st.empty()) nge[it] = -1;
            else nge[it] = st.top();
            st.push(nums2[i]);
        }
        vector<int> ans;
        for(int i=0;i<nums1.size();i++){
            ans.push_back(nge[nums1[i]]);
        }
        return ans;
    }
};
