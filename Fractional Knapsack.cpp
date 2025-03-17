tatic bool compare(pair<double, int>& a, pair<double, int>& b) {
        return a.first > b.first; // Sort in descending order of value/weight
    }
    
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        int n = val.size();
        vector<pair<double, int>> ratio; // {value/weight, index}
        
        // Compute value/weight ratio
        for (int i = 0; i < n; i++) {
            ratio.push_back({(double)val[i] / wt[i], i});
        }

        // Sort in descending order of value/weight
        sort(ratio.begin(), ratio.end(), compare);
        
        double ans = 0;
        
        for (int i = 0; i < n; i++) {
            int index = ratio[i].second; // Get the original index
            if (capacity == 0) break;

            if (wt[index] <= capacity) {
                ans += val[index];
                capacity -= wt[index];
            } else {
                ans += (double)val[index] / wt[index] * capacity;
                break;
            }
        }
        
        return ans;
