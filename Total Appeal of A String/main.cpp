class Solution {
public:
    long long appealSum(string s) {
        vector<int> lasts(26, -1);
        long long res = 0;
        for(int i = 0; i < s.size(); ++i) {
            res += 1ll * (i - lasts[s[i] - 'a']) * ((int)s.size() - i);
            lasts[s[i] - 'a'] = i;
        }
        return res;
    }
};
