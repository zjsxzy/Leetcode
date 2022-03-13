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

const int MAXN = 1005;
int dp[MAXN][2];

class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n = scores.size();
        vector<pair<int, int> > arr;
        for (int i = 0; i < n; i++) {
            arr.push_back({ages[i], scores[i]});
        }
        sort(arr.begin(), arr.end());

        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < n; i++) {
            dp[i][1] = max(dp[i][1], arr[i].second);
            for (int j = 0; j < i; j++) {
                if (arr[i].second >= arr[j].second) {
                    dp[i][1] = max(dp[i][1], dp[j][1] + arr[i].second);
                } else {
                    dp[i][0] = max(dp[i][0], dp[j][0]);
                    dp[i][0] = max(dp[i][0], dp[j][1]);
                }
            }
            // cout << dp[i][0] << " " << dp[i][1] << endl;
        }
        return max(dp[n - 1][0], dp[n - 1][1]);
    }
};

int main() {
    vector<int> s, a;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        s.push_back(x);
    }
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a.push_back(x);
    }
    Solution sol;
    cout << sol.bestTeamScore(s, a) << endl;
    return 0;
}

