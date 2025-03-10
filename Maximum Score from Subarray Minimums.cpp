    int pairWithMaxSum(vector<int> &arr) {
         int N = arr.size();
        int ans = 0;
        for (int i = 1; i < N; i++)
            ans = max(arr[i] + arr[i - 1], ans);
        return ans;
}
