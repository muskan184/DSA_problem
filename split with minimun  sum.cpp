class Solution {
public:
    int splitNum(int num) 
    {
        string s = to_string(num);
        sort(s.begin(), s.end());
        string one = "0", two = "0";
        bool flag = true;
        for(char ch:s)
        {
            flag ? one += ch : two += ch;
            flag = !flag;
        }
        return stoi(one) + stoi(two);;
    }
};
