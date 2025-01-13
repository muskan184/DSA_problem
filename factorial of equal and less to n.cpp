    vector<long long> factorialNumbers(long long n) {
        // Write Your Code here
vector<long long> factorial;
long long fact=1;
int i=1;
while(fact<=n){
    factorial.push_back(fact);
    i++;
    
    fact*=i;
}
return factorial;
    }
