#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        vector<vector<long long>> cnt(26, vector<long long>(26));
        vector<long long> sum(26);
        map<string, set<char>> mp;
        for (auto& s: ideas) {
            sum[s[0] - 'a']++;
            mp[s.substr(1, s.size() - 1)].insert(s[0] - 'a');
        }
        // calc union
        for (auto& [k, v]: mp) {
            vector<int> vec(v.begin(), v.end());
            int sz = vec.size();
            for (int i = 0; i < sz; i++) {
                for (int j = i + 1; j < sz; j++) {
                    cnt[vec[i]][vec[j]]++;
                    cnt[vec[j]][vec[i]]++;
                }
            }
        }
        long long res = 0;
        for (int i = 0; i < 26; i++) {
            for (int j = i + 1; j < 26; j++) {
                res += (sum[i] - cnt[i][j]) * (sum[j] - cnt[i][j]) * 2;
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

