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

int get_status(char c) {
    if (c == 'a') return 1 << 4;
    if (c == 'e') return 1 << 3;
    if (c == 'i') return 1 << 2;
    if (c == 'o') return 1 << 1;
    if (c == 'u') return 1 << 0;
    return 0;
}

class Solution {
public:

    int findTheLongestSubstring(string s) {
        int n = s.size();
        vector<int> state;
        map<int, vector<int> > all_state;
        all_state[0].push_back(0);
        int current_state = 0;
        for (int i = 0; i < n; i++) {
            current_state ^= get_status(s[i]);
            all_state[current_state].push_back(i + 1);
        }

        int res = 0;
        for (auto st : all_state) {
            if (st.second.size() > 1) {
                int k = st.second.size();
                if (st.second[k - 1] - st.second[0] > res) {
                    res = st.second[k - 1] - st.second[0];
                }
            }
        }
        return res;
    }
};

int main() {
    return 0;
}

