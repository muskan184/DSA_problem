class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());
        vector<string> result;

        for (const string& path : folder) {
            if (result.empty() || path.find(result.back() + "/") != 0) {
                result.push_back(path);
            }
        }

        return result;
    }
};
