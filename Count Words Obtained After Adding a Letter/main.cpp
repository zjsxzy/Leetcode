#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define MP make_pair
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

class Solution {
public:
    int wordCount(vector<string>& startWords, vector<string>& targetWords) {
        int n = startWords.size(), m = targetWords.size();
        set<string> st;
        for (auto word: startWords) {
            string cnt(26, 'x');
            for (auto c: word) {
                cnt[c - 'a'] = 'o';
            }
            for (int i = 0; i < 26; i++) {
                if (cnt[i] == 'x') {
                    cnt[i] = 'o';
                    st.insert(cnt);
                    cnt[i] = 'x';
                }
            }
        }
        int res = 0;
        for (auto word: targetWords) {
            string cnt(26, 'x');
            for (auto c: word) {
                cnt[c - 'a'] = 'o';
            }
            if (st.find(cnt) != st.end()) res++;
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

