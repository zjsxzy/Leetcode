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
 * Given a collection of intervals, merge all overlapping intervals.
 *
 * Solution:
 * Sort and implementation.
 *
 */
struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};
bool cmp(const Interval &A, const Interval &B) {
	return A.start == B.start ? A.end < B.end : A.start < B.start;
}
class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
		int n = intervals.size();
		vector<Interval> ret;
		int i = 0;
		while (i < n) {
			int start = intervals[i].start, end = intervals[i].end;
			int j = i + 1;
			for (; j < n && intervals[j].start <= end; j++)
				end = max(end, intervals[j].end);
			ret.push_back(Interval(start, end));
			i = j;
		}
		return ret;
    }
};
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	int n;
	vector<Interval> inter;
	cin >> n;
	while (n--) {
		int a, b;
		cin >> a >> b;
		inter.push_back(Interval(a, b));
	}
	Solution sol;
	vector<Interval> ret = sol.merge(inter);
	for (int i = 0; i < ret.size(); i++)
		cout << ret[i].start << " " << ret[i].end << endl;
	return 0;
}

