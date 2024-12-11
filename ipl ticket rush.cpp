#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int t,n,x;
    cin>>t;
    while(t--){
        cin>>n>>x;
        if(x>n){
            cout<<0<<endl;
        }else{
        cout<<n-x<<endl;
        }
    }
    return 0;
}
