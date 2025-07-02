class Solution {
public:
    string decodeString(string s) {
        stack<string>strStack;
        stack<int>numStack;
        string currStr="";
        int num = 0;

        for(char c:s){
            if(isdigit(c)){
                num=num*10+(c-'0');
            }else if(c == '['){
                numStack.push(num);
                strStack.push(currStr);
                num=0;
                currStr = "";
            }else if(c == ']'){
                string temp= currStr;
                currStr = strStack.top();
                strStack.pop();

                int repeat = numStack.top();
                numStack.pop();

                while(repeat--){
                    currStr+=temp;
                }
            }
            else{
                currStr+=c;
            }
        }
        return currStr;
    }
};
