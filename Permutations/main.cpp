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
 * Description: Given a collection of numbers, return all possible permutations.
 *
 * Solution: Brute force
 *
 */
class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
		vector<vector<int> > res;
		sort(num.begin(), num.end());
		do {
			res.push_back(num);
		} while (next_permutation(num.begin(), num.end()));
		return res;
    }
};
int main() {
}

