#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

class Solution {
public:

    int maximumRemovals(string s, string p, vector<int>& removable) {
        int n = s.size();
        int lo = 0, hi = removable.size(), ret = 0;
        // cout << check(2, s, p, removable) << endl;
        while (lo <= hi) {
            int mid = (lo + hi) >> 1;
            if (check(mid, s, p, removable)) {
                ret = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return ret;
    }

    bool check(int k, string &s, string &p, vector<int> &removable) {
        string rs = "";
        vector<int> vec;
        for (int i = 0; i < k; i++) {
            vec.push_back(removable[i]);
        }
        sort(vec.begin(), vec.end());

        int i = 0, j = 0, l = 0;
        int n = s.size(), m = p.size();
        while (i < n && j < m) {
            while (l < vec.size() && i == vec[l]) {
                i++; l++;
            }
            if (i >= n) return false;
            if (s[i] == p[j]) {
                j++;
            }
            i++;
        }
        return j == m;
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

