class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        
        unordered_map<char,int>charCount;
        for(auto c:chars){
            charCount[c]++;
        }

        int totalLength=0;
        for(auto word:words){
          unordered_map<char,int>wordCount;
          for(auto c:word){
            wordCount[c]++;
          }
        

        bool formed=true;

        for(auto& ent:wordCount){
            char c= ent.first;
            int  f=ent.second;

            if(charCount[c]<f){
                formed=false;
            }
        }

        if(formed){
            totalLength += word.length();
        }
      }

      return  totalLength;
    }
};
