  bool armstrongNumber(int n) {
        // code here
        int ogn=n;
        int ans=0;
        while(n!=0){
            int mod= n%10;
             ans=ans+mod*mod*mod;
             n=n/10;
        }
        return ans == ogn;

    }
