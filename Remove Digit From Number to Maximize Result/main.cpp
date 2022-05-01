class Solution {
public:
    string removeDigit(string number, char digit) {
        int n = number.size();
        vector<string> res;
        for (int i = 0; i < n; i++) {
            if (number[i] == digit) {
                string s = number.substr(0, i);
                string t = number.substr(i + 1, n - i - 1);
                res.push_back(s + t);
            }
        }
        sort(res.rbegin(), res.rend());
        return res[0];
    }
};
