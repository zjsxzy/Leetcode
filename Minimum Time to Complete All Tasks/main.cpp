#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class Solution {
public:
    int findMinimumTime(vector<vector<int>>& tasks) {
        sort(tasks.begin(), tasks.end(), [](vector<int>& A, vector<int>& B) {
            if (A[1] == B[1]) return A[0] < B[0];
            return A[1] < B[1];
        });
        vector<int> vst(2005, 0);
        for (auto t: tasks) {
            int l = t[0], r = t[1], tot = t[2];
            int cnt = 0;
            for (int i = l; i <= r; i++) cnt += vst[i];
            if (cnt >= tot) continue;
            for (int i = r; i >= l; i--) {
                if (!vst[i] && cnt < tot) {
                    vst[i] = 1;
                    cnt++;
                }
            }
        }
        int res = 0;
        for (int i = 1; i <= 2000; i++) res += vst[i];
        return res;
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

