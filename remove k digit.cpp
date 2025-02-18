class Solution {
public:
    string removeKdigits(string num, int k) {
        if(k==num.size()) return "0";

        stack<int>s;
        s.push(num[0]-'1'+1);

        for(int i=1; i<num.size(); i++){
            int temp=num[i]-'1'+1;
            while(k>0 && !s.empty() && s.top()>temp){
                s.pop();
                k--;
            }
            s.push(temp);
        }

        string ans="";
        while(!s.empty()){
            ans+=(s.top()-1+'1');
            s.pop();
        }
        
        if(k>0) ans=ans.substr(k);
        reverse(ans.begin(),ans.end());

        int count=0;
        for(int i=0; i<ans.size(); i++){
            if(ans[i]!='0') break; 
            count++;
        }
        if(count==ans.size()) return "0";
        return ans.substr(count);
    }
};
