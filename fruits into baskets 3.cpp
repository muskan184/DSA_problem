class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
      int count = 0;
        int temp = INT_MAX;
        for(int i = 0; i < (int)fruits.size(); i++){
            if(fruits[i] >= temp){
                count++;
                continue;
            }
            for(int j = 0; j < (int)baskets.size(); j++){
                if(fruits[i] <= baskets[j]){
                    baskets.erase(baskets.begin()+j);
                    break;
                }
                if(j==(int)baskets.size()-1){ //cannot be placed in any basket
                    temp = min(temp,fruits[i]);
                    count++;
                }
            }
        }
        
        return count;
    }
};
