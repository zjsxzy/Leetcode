class Solution {
public:
    int longestContinuousSubstring(string s) {
        s += '#';
        int curr = 1, res = 1, n = s.size();
        char c = s[0];
        for (int i = 1; i < n; i++) {
            if (s[i] - c == 1) {
                curr++;
            } else {
                curr = 1;
            }
            c = s[i];
            res = max(res, curr);
        }
        return res;
    }
};
