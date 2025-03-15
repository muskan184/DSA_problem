class Solution {
public:
    long long maxWeight(vector<int>& p) {
      sort(p.begin(),p.end());
      int n = p.size(), days=n/4; 
      int index=n-1;
      long long totalW=0;

      for(int i =1;i<=days;i+=2){
        totalW += p[index--];
      }
      index--;
    
      for(int i =2;i<=days;i+=2){
        totalW += p[index];
        index-=2;
      }
    return totalW;
    }
};
