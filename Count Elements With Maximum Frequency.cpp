class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int>freq;

        for(int num :nums){
            freq[num]++;
        }

        int max_freq=0;
        for(auto& it :freq){
            if(it.second > max_freq){
                max_freq = it.second;
            }
        }
        int total = 0;
        for(auto &it :freq){
            if(it.second == max_freq){
                total+=it.second;
            }
        }
        return total;

    }
};
