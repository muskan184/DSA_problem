#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
  int t;
  int r1,r2,r3,r4;
  cin>>t;
  while(t--){
      cin>>r1>>r2>>r3>>r4;
      if(r1==1 || r2==1 || r3==1 || r4==1){
          std::cout <<"out" << std::endl;
      }else{
          cout<<"in"<<endl;
      }
  }
  return 0;
}
