    class Solution {
public:
    int countConsistentStrings(string all, vector<string>& words) {
        int count =0;
       unordered_set<char>ch(all.begin(),all.end());
        int n =words.size();
     for(int i =0;i<n;i++){
              bool finds=true;
        for(char c:words[i]){
             if (ch.find(c) == ch.end()){
                finds=false;
               break;
          }
        }
        if(finds){
            count++;
        }
     }
     return count;
    }
};
