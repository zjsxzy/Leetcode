#include <map>
#include <set>
#include <list>
#include <cmath>
#include <queue>
#include <stack>
#include <bitset>
#include <vector>
#include <cstdio>
#include <string>
#include <cassert>
#include <climits>
#include <sstream>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define PB push_back
#define MP make_pair
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
#define FOREACH(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
typedef long long LL;

class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        vector<int> cnt(k), res;
        set<int> st;
        for (int i = 0; i < k; i++) {
            st.insert(i);
        }
        int n = arrival.size();
        priority_queue<pair<int, int> > pq;
        for (int i = 0; i < n; i++) {
            int pos = i % k;
            int tim = arrival[i], lod = load[i];
            while (!pq.empty() && pq.top().first * -1 <= tim) {
                st.insert(pq.top().second);
                pq.pop();
            }
            if (st.empty()) continue;
            else {
                auto it = st.lower_bound(pos);
                if (it == st.end()) it = st.begin();
                pos = *it;
                st.erase(pos);
                cnt[pos]++;
                pq.push(make_pair(-(tim + lod), pos));
            }
        }
        int mx = 0;
        for (int i = 0; i < k; i++) {
            if (cnt[i] > mx) {
                mx = cnt[i];
            }
        }
        for (int i = 0; i < k; i++) {
            if (cnt[i] == mx) {
                res.push_back(i);
            }
        }
        return res;
    }
};

int main() {
}

