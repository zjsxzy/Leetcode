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
 * Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers.
 *
 * Solution:
 * Enumerate a, b, search the closest element around target - (a + b) using binary search.
 */
class Solution {
public:
	int N;
	vector<int> Num;

	int next(int i) {
		int j = i + 1;
		while (j < N && Num[i] == Num[j]) {
			j++;
		}
		return j;
	}

    int threeSumClosest(vector<int> &num, int target) {
		N = num.size();
		this->Num = num;
		sort(Num.begin(), Num.end());
		int minDiff = 0x3f3f3f3f;
		int closestSum = -1;
		for (int i = 0; i + 2 < N; i = next(i)) {
			int a = Num[i];
			for (int j = i + 1; j + 1 < N; j = next(j)) {
				int b = Num[j];
				int x = target - (a + b);
				int idx = lower_bound(Num.begin() + j + 2, Num.end(), x) - Num.begin();
				if (idx < N) {
					int sum = a + b + Num[idx];
					//cout << a << " " << b << " " << Num[idx] << " " << sum << endl;
					if (abs(sum - target) < minDiff) {
						minDiff = abs(sum - target);
						closestSum = sum;
					}
				}
				if (idx > 0) {
					idx--;
					int sum = a + b + Num[idx];
					//cout << a << " " << b << " " << Num[idx] << " " << sum << endl;
					if (abs(sum - target) < minDiff) {
						minDiff = abs(sum - target);
						closestSum = sum;
					}
				}
			}
		}
		return closestSum;
    }
};
int main() {
	int A[] = {-1, 2, 1, -4};
	vector<int> B(A, A + 4);
	Solution sol;
	cout << sol.threeSumClosest(B, 1) << endl;
	return 0;
}

