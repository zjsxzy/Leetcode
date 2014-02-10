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
 * Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.
 *
 * Solution:
 * Hash
 */
class Solution {
public:
	int n;
	map<int, int> numCnt;
	map<int, vector<pair<int, int> > > sumPair;

    vector<vector<int> > fourSum(vector<int> &num, int target) {       
		n = num.size();
		// calculate numCnt
		for (int i = 0; i < n; i++) {
			numCnt[num[i]]++;
		}
		sort(num.begin(), num.end());
		num.resize(unique(num.begin(), num.end()) - num.begin());
		// calculate pairCnt
		n = num.size();
		for (int i = 0; i < n; i++) {
			int a = num[i];
			for (int j = i + (numCnt[a] > 1 ? 0 : 1); j < n; j++) {
				int b = num[j];
				sumPair[a + b].push_back(make_pair(a, b));
			}
		}
		vector<vector<int> > ret;
		for (int i = 0; i < n; i++) {
			int a = num[i];
			for (int j = i + (numCnt[a] > 1 ? 0 : 1); j < n; j++) {
				int b = num[j];
				int x = target - (a + b);
				if (sumPair.find(x) == sumPair.end()) continue;
				for (int k = 0; k < sumPair[x].size(); k++) {
					int c = sumPair[x][k].first, d = sumPair[x][k].second;
					if (c < b) continue;
					int numC = 1 + (b == c) + (a == c);
					int numD = 1 + (c == d ? numC : 0);
					if (numCnt[c] >= numC && numCnt[d] >= numD) {
						vector<int> temp;
						temp.push_back(a); temp.push_back(b); temp.push_back(c); temp.push_back(d);
						ret.push_back(temp);
					}
				}
			}
		}
		return ret;
    }
};
int main() {
	int myints[] = {1, 0, -1, 0, -2, 2};
	vector<int> A(myints, myints + 6);
	Solution sol;
	vector<vector<int> > ret = sol.fourSum(A, 0);
	for (int i = 0; i < ret.size(); i++) {
		for (int j = 0; j < ret[i].size(); j++) {
			cout << ret[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}

