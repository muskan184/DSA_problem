class Solution {
public:
    int minAddToMakeValid(string s) {
        int cnt=0,cnt1=0;
        int n = s.length();
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                cnt++;
            }else{
                if(cnt>0){
                    cnt--;
                }else{
                    cnt1++;
                }
            }
        }
        return cnt+cnt1;
    }
};
