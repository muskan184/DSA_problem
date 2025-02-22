class Solution {
public:

    // next waale vector me nextsmallerElement ka index store krenge

    void nextSmallerElement(vector<int>& heights, vector<int> &next) {
        stack<int> st;
        st.push(-1);
        int n = heights.size();

        for (int i = n-1; i>=0; i--) {
            while (st.top() != -1 && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            next.push_back(st.top());
            st.push(i);
        }
    }

    void prevSmallerElement(vector<int>& heights, vector<int> &prev) {
        stack<int> st;
        st.push(-1);
        int n = heights.size();

    
        for (int i = 0; i<n; i++) {
            while (st.top() != -1 && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            prev.push_back(st.top());
            st.push(i);
        }
    }

    int largestRectangleArea(vector<int>& heights) {
        vector<int> next;
        vector<int> prev;
        nextSmallerElement(heights, next);
        reverse(next.begin(), next.end());
        // extra layer of processing
        for (int i = 0; i<next.size(); i++) {
            if (next[i] == -1) {
                next[i] = next.size();
            }
        }

        prevSmallerElement(heights, prev);

        vector<int> area;
        for (int i = 0; i<next.size(); i++) {
            int width = next[i]-prev[i]-1;
            int height = heights[i];
            int currArea = width*height;
            area.push_back(currArea);
        }

        int maxArea = INT_MIN;
        for (int i = 0; i<area.size(); i++) {
            maxArea = max(maxArea, area[i]);
        }

        return maxArea;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        
        // convert char to int
        vector<vector<int>> v;
        int n = matrix.size();
        int m = matrix[0].size();
        for (int i = 0; i<n; i++) {
            vector<int> t;
            for (int j = 0; j<m; j++) {
                t.push_back(matrix[i][j]-'0');
            }
            v.push_back(t);
        }

        int area = largestRectangleArea(v[0]);
        for (int i = 1; i<n; i++) {
            for (int j = 0; j<m; j++) {
                if (v[i][j]) {
                    v[i][j] += v[i-1][j];
                }
                // 0
                else {
                    v[i][j] = 0;
                }
            }
            area = max(area, largestRectangleArea(v[i]));
        }

        return area;
    }
};
