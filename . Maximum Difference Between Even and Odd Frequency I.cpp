

class Solution {
public:
    int maxDifference(std::string s) {
        std::unordered_map<char, int> freq;

        // Step 1: Count the frequency of each character
        for (char c : s) {
            freq[c]++;
        }

        // Step 2: Separate odd and even frequencies
        std::vector<int> oddFreq, evenFreq;
        for (const auto& pair : freq) {
            if (pair.second % 2 == 0) {
                evenFreq.push_back(pair.second);
            } else {
                oddFreq.push_back(pair.second);
            }
        }

        // Step 3: Find the maximum difference
        int maxDiff = INT_MIN;
        for (int odd : oddFreq) {
            for (int even : evenFreq) {
                maxDiff = std::max(maxDiff, odd - even);
            }
        }

        return maxDiff;
    }
};
