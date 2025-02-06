#include <stack>
#include <climits>

class MinStack {
public:
    std::stack<long long> st;
    long long mini = INT_MAX;

    void push(int val) {
        if (st.empty()) {
            mini = val;
            st.push(val);
        } else {
            if (val < mini) {
                st.push(2LL * val - mini); // Store encoded value
                mini = val; // Update minimum
            } else {
                st.push(val);
            }
        }
    }

    void pop() {
        if (st.empty()) return;

        long long x = st.top();
        st.pop();
        if (x < mini) {
            mini = 2 * mini - x; // Recover previous minimum
        }
    }

    int top() {
        if (st.empty()) return -1;

        long long x = st.top();
        return (x < mini) ? mini : x; // If encoded, return mini
    }

    int getMin() {
        return mini;
    }
};
