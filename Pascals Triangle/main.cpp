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

/*
 * Description: Generate Pascal's Tirangle.
 *
 * Solution: Brute force.
 *
 */
class Solution {
public:
    vector<vector<int> > generate(int numRows) {
		vector<vector<int> > res;
		for (int i = 0; i < numRows; i++) {
			vector<int> temp;
			temp.PB(1);
			for (int j = 1; j < i; j++) {
				temp.PB(res[i - 1][j - 1] + res[i - 1][j]);
			}
			if(i > 0) temp.PB(1);
			res.PB(temp);
		}
		return res;
    }
};
int main() {
	Solution sol;
	vector<vector<int> > out = sol.generate(5);
	for (int i = 0; i < out.size(); i++) {
		for (int j = 0; j < out[i].size(); j++) {
			cout << out[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}

