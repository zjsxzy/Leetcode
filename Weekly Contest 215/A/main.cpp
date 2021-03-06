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

class OrderedStream {
public:
    vector<string> s;
    int ptr;

    OrderedStream(int n) {
        s.resize(n);
        ptr = 1;
    }

    vector<string> insert(int id, string value) {
        vector<string> res;
        cout << id << " " << ptr << endl;
        s[id - 1] = value;
        if (id == ptr) {
            int i;
            for (i = ptr - 1; s[i].size() > 0 && i < s.size(); i++) {
                res.push_back(s[i]);
            }
            ptr = i + 1;
        }
        return res;
    }
};

int main() {
    return 0;
}

