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
    int minimumEffort(vector<vector<int>>& tasks) {
        int n = tasks.size();
        priority_queue<pair<int, int> > pq;
        for (auto x : tasks) {
            pq.push({x[1] - x[0], x[0]});
        }
        int sum = 0, energy = 0;
        while (!pq.empty()) {
            auto x = pq.top(); pq.pop();
            int st = x.first + x.second, en = x.second;
            // cout << energy << " " << sum << " " << x.first << " " << x.second << endl;
            if (energy - sum < st) {
                energy += st - (energy - sum);
            }
            sum += en;
        }
        return energy;
    }
};

int main() {
}

