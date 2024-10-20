#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class Solution {
public:
    vector<string> stringSequence(string target) {
        vector<string> ans;
        string s = "";
        for (char c: target) {
            ans.push_back(s + 'a');
            for (int i = 0; i < c - 'a'; i++) {
                ans.push_back(s + (char)('a' + i + 1));
            }
            s += c;
        }
        return ans;
    }
};

void solve() {
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int ts = 1;
    // cin >> ts;
    for (int t = 1; t <= ts; t++) {
       solve();
    }
    return 0;
}

