#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n = skill.size();
        sort(skill.begin(), skill.end());
        long long sum = 0;
        map<long long, int> cnt;
        for (auto x: skill) {
            sum += x;
            cnt[x]++;
        }
        if (sum % (n / 2) != 0) return -1;
        long long team = sum / (n / 2);
        long long res = 0;
        // cout << team << endl;
        for (int i = 0; i < n / 2; i++) {
            if (cnt.find(team - skill[i]) == cnt.end() || cnt[team - skill[i]] <= 0) return -1;
            // cout << skill[i] << ' ' << team - skill[i] << endl;
            res += (long long)skill[i] * (team - skill[i]);
            cnt[team - skill[i]]--;
            cnt[skill[i]]--;
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

