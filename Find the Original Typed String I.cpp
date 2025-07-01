class Solution {
public:
    int possibleStringCount(string word) {
        int ans=1;
        int n= word.size();

        for(int i=0;i<n;i++){
            if(word[i]==word[i+1]) ans+=1;
        }
        return ans;
    }
};
