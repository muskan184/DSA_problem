    int countSubstrdistint(string& s, int k) {
    int n=s.size();
    int left=0,right=0,distcount=0,result=0;
    unordered_map<char,int> charCount;
    
    while(right<n){
        charCount[s[right]]++;
        if(charCount[s[right]]==1){
            distcount++;
        }
        right++;
        
        while(distcount >k){
        charCount[s[left]]--;
        if(charCount[s[left]]==0){
            distcount--;
        }
        left++;
        }
       result+=(right-left);
    }
    return result;
    }
    
       int countSubstr(string& s, int k) {
           return countSubstrdistint(s,k)-countSubstrdistint(s,k-1);
       }
