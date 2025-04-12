class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> ans;

        for (int i = 0; i < words.size(); ++i) {
            if (i == 0) {
                ans.push_back(words[i]);
            } else {
                string prev = words[i - 1];
                string curr = words[i];
                sort(prev.begin(), prev.end());
                sort(curr.begin(), curr.end());

                if (prev != curr) {
                    ans.push_back(words[i]);
                }
            }
        }

        return ans;
    }
};
