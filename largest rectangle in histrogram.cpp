class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int>st;
        long long maxArea=0;

        for(int i=0;i<heights.size();i++){
            while(!st.empty() && heights[st.top()] > heights[i]){
                int element =st.top();
                st.pop();
                int nse=i;
                int pse = st.empty() ? -1: st.top();
                maxArea = max((long long) heights[element]*(nse-pse-1),maxArea);
            }
            st.push(i);
        }
        while(!st.empty()){
            int nse= heights.size();
            int element =st.top();
            st.pop();
            int pse = st.empty() ? -1:st.top();
            maxArea = max((long long) heights[element]*(nse-pse-1),maxArea);
        }
        return maxArea;
    }
}; 
