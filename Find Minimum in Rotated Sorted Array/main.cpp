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
 * Description:
 * Suppose a sorted array is rotated at some pivot unknown to you beforehand.
 *
 * Solution:
 * Binary Search.
 *
 */
class Solution {
public:
    int findMin(vector<int> &num) {
		int n = num.size();
		int lo = 0, hi = n - 1;
		while (lo <= hi) {
			int mid = (lo + hi) >> 1;
			if (num[mid] > num[n - 1]) lo = mid + 1;
			else hi = mid - 1;
		}
		return num[lo];
    }
};
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	int n;
	cin >> n;
	vector<int> num(n);
	for (int i = 0; i < n; i++)
		cin >> num[i];
	Solution sol;
	cout << sol.findMin(num) << endl;
	return 0;
}

