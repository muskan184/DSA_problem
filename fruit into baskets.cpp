class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        
        int size = fruits.size();
        map<int,int>mp;
        int l=0,r=0,maxlen=0;

        while(r<size){
            mp[fruits[r]]++;
            while(mp.size()>2 && l<r){
                mp[fruits[l]]--;
                if(mp[fruits[l]]==0){
                    mp.erase(fruits[l]);
                }
                l++;
            }
            if(mp.size() <= 2){
                maxlen = max(maxlen,r-l+1);
            }
            r++;
        }
        return maxlen;

    }
};
