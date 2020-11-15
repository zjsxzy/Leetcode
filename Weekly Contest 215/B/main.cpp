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
    bool closeStrings(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        if (n != m) return false;
        map<char, int> cnt1, cnt2;
        for (int i = 0; i < n; i++) {
            cnt1[word1[i]]++;
            cnt2[word2[i]]++;
        }
        multiset<int> st;
        for (auto x : cnt2) {
            st.insert(x.second);
        }

        for (auto x : cnt1) {
            // cout << x.first << " " << x.second << endl;
            if (cnt2.find(x.first) == cnt2.end()) {
                return false;
            }
            auto it = st.find(x.second);
            if (it == st.end()) {
                return false;
            } else {
                st.erase(it);
            }
        }
        return true;
    }
};

int main() {
    return 0;
}

