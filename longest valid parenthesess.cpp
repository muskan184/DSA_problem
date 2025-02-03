class Solution {
public:
    int longestValidParentheses(string s) {
        int l=0,r=0,ans=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')
            l++;
            else if(s[i]==')')
            r++;
            if(r>l)
            {
                l=0;
                r=0;
            }
            else if(r==l)
            {
                ans=max(l*2,ans);
            }
        }
        l=0,r=0;
        for(int i=s.size()-1;i>=0;i--)
        {
            if(s[i]=='(')
            l++;
            else if(s[i]==')')
            r++;
            if(r<l)
            {
                l=0;
                r=0;
            }
            else if(r==l)
            {
                ans=max(l*2,ans);
            }
        }
        return ans;
    }
};
