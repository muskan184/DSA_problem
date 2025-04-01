class Solution {
public:
    bool checkIfPangram(string s) {
        vector<bool>str(26,0) ;
        for(int i=0;i<s.size();i++){
            str[s[i]-'a']=1;
        }

        for(int i=0;i<26;i++){
            if(str[i]==0) return 0;
        }

        return 1;
    }
};
