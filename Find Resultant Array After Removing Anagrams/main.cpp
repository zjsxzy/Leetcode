#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> vec;
        vector<string> res;
        int n = words.size();
        for (int i = 0; i < n; i++) {
            string w = words[i];
            sort(w.begin(), w.end());
            vec.push_back(w);
        }
        res.push_back(words[0]);
        for (int i = 1; i < n; i++) {
            if (vec[i] != vec[i - 1]) res.push_back(words[i]);
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

