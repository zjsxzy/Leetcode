#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define MP make_pair
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

class FindSumPairs {
public:
    vector<int> v1, v2;
    int n1, n2;
    map<int, int> cnt;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        v1 = nums1;
        v2 = nums2;
        n1 = nums1.size();
        n2 = nums2.size();
        for (auto &x : v2) {
            cnt[x]++;
        }
    }

    void add(int index, int val) {
        cnt[v2[index]]--;
        v2[index] += val;
        cnt[v2[index]]++;
    }

    int count(int tot) {
        int res = 0;
        for (auto &x : v1) {
            int y = tot - x;
            if (cnt.find(y) != cnt.end()) {
                res += cnt[y];
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
    solve();
    return 0;
}

