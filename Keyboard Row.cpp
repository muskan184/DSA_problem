class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        string row1 = "qwertyuiop";
        string row2 = "asdfghjkl";
        string row3 = "zxcvbnm";

        vector<string> ans;
        for (string word : words) {
            string lowercase = word;
            transform(lowercase.begin(), lowercase.end(), lowercase.begin(),
                      ::tolower);

            bool isrow1 = true, isrow2 = true, isrow3 = true;

            for (char ch : lowercase) {
                if (row1.find(ch) == string::npos)
                    isrow1 = false;
                if (row2.find(ch) == string::npos)
                    isrow2 = false;
                if (row3.find(ch) == string::npos)
                    isrow3 = false;
            }

            if (isrow1 || isrow2 || isrow3)
                ans.push_back(word);
        }
        return ans;
    }
};
