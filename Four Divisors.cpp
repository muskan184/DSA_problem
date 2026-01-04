class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
       int totalSum = 0;

       for(int x : nums){
            int cnt = 0;
            int divSum = 0;
             
             for(int i=1;i*i<=x;i++){
                if(x%i == 0){
                    int d1 =i;
                    int d2 = x/i;

                    if(d1 == d2){
                        cnt++;
                        divSum += d1;
                    }else{
                        cnt += 2;
                        divSum += d1+d2;
                    }
                    if(cnt > 4) break;
                }
             }
             if(cnt == 4) totalSum += divSum;
       } 
       return totalSum ;
    }
};
