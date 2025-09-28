class Solution {
public:
void insertInSortedOrder(stack<int> &st, int element) {
    if (st.empty() || st.top() < element) {
        st.push(element);
        return;
    }

    int top = st.top();
    st.pop();
    insertInSortedOrder(st, element);

    st.push(top);
}

    void sortStack(stack<int> &st) {
    if (st.empty()) return;  

    int top = st.top();
    st.pop();

    sortStack(st);               
    insertInSortedOrder(st, top);
    }
};
