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
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        for (int i = 0; i < arr.size();) {
            int x = arr[i], p = i, l = 0;
            bool flag = false;
            for (int j = 0; j < pieces.size(); j++) {
                if (pieces[j][0] == x) {
                    for (int k = 0; k < pieces[j].size(); k++) {
                        if (arr[i] != pieces[j][k]) {
                            return false;
                        } else {
                            i++;
                        }
                    }
                    flag = true;
                    l = pieces[j].size();
                }
            }
            cout << p << " " << l << endl;
            if (!flag) return false;
            else i = p + l;
        }
        return true;
    }
};

int main() {
    return 0;
}

