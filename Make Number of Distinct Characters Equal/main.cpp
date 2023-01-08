#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class Solution {
public:
    bool isItPossible(string word1, string word2) {
        vector<int> c1(26), c2(26);
        for (auto c: word1) c1[c - 'a']++;
        for (auto c: word2) c2[c - 'a']++;
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 26; j++) {
                if (c1[i] == 0 || c2[j] == 0) continue;

                c1[i]--; c2[i]++;
                c2[j]--; c1[j]++;
                int s1 = 0, s2 = 0;
                for (int k = 0; k < 26; k++) {
                    if (c1[k] != 0) s1++;
                    if (c2[k] != 0) s2++;
                }
                if (s1 == s2) {
                    return true;
                }
                c1[i]++; c2[i]--;
                c2[j]++; c1[j]--;

            }
        }
        return false;
    }
};

void solve() {
}

int main() {
    int ts = 1;
    // cin >> ts;
    for (int t = 1; t <= ts; t++) {
        solve();
    }
    return 0;
}

