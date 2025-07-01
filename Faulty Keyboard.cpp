class Solution {
public:
    string finalString(string s) {
      string result;

      for(char ch : s){
        if(ch == 'i')
        reverse(result.begin(),result.end());
        
        else
        result.push_back(ch);
      }
      return result;
    }
};
