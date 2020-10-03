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
    vector<vector<int> > restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int n = rowSum.size(), m = colSum.size();
        vector<vector<int> > mat;
        for (int i = 0; i < n; i++) {
            vector<int> vec;
            for (int j = 0; j < m; j++) {
                int val = min(rowSum[i], colSum[j]);
                vec.push_back(val);
                rowSum[i] -= val;
                colSum[j] -= val;
            }
            mat.push_back(vec);
        }
        return mat;
    }
};

int main() {
}

