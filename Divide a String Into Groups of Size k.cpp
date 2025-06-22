class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string>ans;
        string word;

        for(char c:s){
            word.push_back(c);
            if(word.length() == k){
                ans.push_back(word);
                word.clear();
            }
        }
         if(!word.empty()){
            while(word.length() < k){
            word.push_back(fill);
            }
            ans.push_back(word);
         }
        return ans;
    }
};
