string sort(string s){
    //complete the function here
    vector<int>arr(26,0);
    
    for(int i=0;i<s.size();i++){
        arr[s[i]-'a']++;
    }
    
    string ans;
    for(int i=0;i<26;i++){
        char c= 'a'+i;
        while(arr[i]){
            ans+=c;
            arr[i]--;
        }
    }
    return ans;
}
