#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

class Solution {
public:
    vector<long long> kthPalindrome(vector<int>& queries, int intLength) {
        string s = "1";
        for (int i = 0; i < intLength / 2 - 1; i++) {
            s += "0";
        }
        string t = s + "0";
        if (intLength & 1 && intLength > 1) {
            s += "0";
            t += "0";
        }
        long long lo = stoll(s), hi = stoll(t);
        cout << lo << " " << hi << endl;
        vector<long long> res;
        for (auto& q: queries) {
            if (intLength % 2 == 0) {
                if (q > hi - lo) {
                    res.push_back(-1);
                } else {
                    long long x = lo + q - 1;
                    string fi = to_string(x);
                    string se = fi;
                    reverse(se.begin(), se.end());
                    res.push_back(stoll(fi + se));
                }
            } else {
                if (q > hi - lo) {
                    res.push_back(-1);
                } else {
                    long long x = lo + q - 1;
                    string fi = to_string(x);
                    string se = fi.substr(0, fi.size() - 1);
                    reverse(se.begin(), se.end());
                    res.push_back(stoll(fi + se));
                }
            }
        }
        return res;
    }
};

void solve() {
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    solve();
    return 0;
}

