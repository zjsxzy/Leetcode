#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class Solution {
public:
    string largestGoodInteger(string num) {
        int n = num.size();
        vector<string> ans;
        for (int i = 0; i + 2 < n; i++) {
            string sub = num.substr(i, 3);
            if (sub[0] == sub[1] && sub[1] == sub[2]) {
                ans.push_back(sub);
            }
        }
        sort(ans.begin(), ans.end());
        if (ans.size() == 0) return "";
        else return ans[ans.size() - 1];
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

