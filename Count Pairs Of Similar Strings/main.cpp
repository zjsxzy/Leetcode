#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class Solution {
public:
    int similarPairs(vector<string>& words) {
        int n = words.size(), res = 0;
        for (int i = 0; i < n; i++) {
            vector<int> a(26);
            for (auto c: words[i]) a[c - 'a']++;
            for (int j = i + 1; j < n; j++) {
                vector<int> b(26);
                for (auto c: words[j]) b[c- 'a']++;
                bool flag = true;
                for (int k = 0; k < 26; k++) {
                    if (a[k] == 0 && b[k] > 0) {
                        flag = false;
                        break;
                    }
                    if (b[k] == 0 && a[k] > 0) {
                        flag = false;
                        break;
                    }
                }
                if (flag) res++;
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
    int ts = 1;
    // cin >> ts;
    for (int t = 1; t <= ts; t++) {
        solve();
    }
    return 0;
}

