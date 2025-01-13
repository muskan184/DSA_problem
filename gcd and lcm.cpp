  int gcd (int a,int b){
      if(b==0)
      return a;
      return gcd(b,a%b);
  }
  
  int lcm(int a, int b){
      return (a*b)/gcd(a,b);
  }
    vector<int> lcmAndGcd(int a, int b) {
        // code here
        vector<int>result;
         result.push_back(lcm(a,b));
        result.push_back(gcd(a,b));
        
             return result;
    }
