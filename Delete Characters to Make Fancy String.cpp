class Solution {
public:
    string makeFancyString(string s) {
        int count =1;
        string ans;
        ans+=s[0];

        for(int i=1;i<s.length();i++){
            if(s[i-1] == s[i]){
                count++;
        }
        else{
            count=1;
        }

        if(count <= 2){
            ans += s[i];
        }
    }
        return ans;
    }
};
