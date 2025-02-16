class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for (auto ast : asteroids) {
            bool des = false;
            if (ast > 0) {
                st.push(ast);
            }
            else {
                if (st.empty() || st.top() < 0) {
                    st.push(ast);
                }
                else {
                    while (!st.empty() && st.top() > 0) {
                        if (abs(ast) == st.top()) {
                            des = true;
                            st.pop();
                            break;
                        }
                        else if (abs(ast) > st.top()) {
                            st.pop();
                        }
                        else {
                            des = true;
                            break;
                        }
                    }
                    if (!des) {
                        st.push(ast);
                    }
                }
            }
        }
        vector<int> ans(st.size());
        for (int i = st.size()-1; i>=0; i--) {
            ans[i] = st.top();
            st.pop();
        }

        return ans;
    }
};
