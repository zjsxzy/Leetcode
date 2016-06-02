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
 * Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
 *
 * Solution:
 * Enumerate a, b, check whether there exist such a c in the array.
 */
class Solution {
public:
	int N;
	vector<int> Num;
	map<int, int> cnt;

	int next(int i) {
		int j = i + 1;
		while (j < N && Num[i] == Num[j]) {
			j++;
		}
		return j;
	}
	
    vector<vector<int> > threeSum(vector<int> &num) {
		N = num.size();
		this->Num = num;
		sort(Num.begin(), Num.end());
		for (int i = 0; i < N; i++) {
			cnt[Num[i]]++;
		}
		vector<vector<int> > ret;
		for (int i = 0; i < N; i = next(i)) {
			int a = Num[i];
			for (int j = i + 1; j < N; j = next(j)) {
				int b = Num[j];
				int c = -(a + b);
				if (c < b) continue;
				if (cnt.find(c) == cnt.end()) continue;
				int leastCnt = 0;
				if (c > b) leastCnt = 1;
				else if (b > a) leastCnt = 2;
				else leastCnt = 3;
				if (cnt[c] >= leastCnt) {
					vector<int> temp;
					temp.PB(a); temp.PB(b); temp.PB(c);
					ret.PB(temp);
				}
			}
		}
		return ret;
    }
};

int main() {
	Solution sol;
	int myint[] = {-1, 0, 1, 2, -1, -4};
	vector<int> num(myint, myint + 6);
	vector<vector<int> > ans = sol.threeSum(num);
	for (int i = 0; i < ans.size(); i++) {
		FOREACH(it, ans[i]) {
			cout << *it << " ";
		}
		cout << endl;
	}
	return 0;
}

