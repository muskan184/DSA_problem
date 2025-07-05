class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int ,int >freq;
        int n=arr.size();

        for(int i=0;i<n;i++){
            freq[arr[i]]++;
        }
      int maxLucky = -1;
        for(auto it : freq){
            if(it.first == it.second)  maxLucky = max(maxLucky, it.first);
            }
        
        return maxLucky;
    }
};
