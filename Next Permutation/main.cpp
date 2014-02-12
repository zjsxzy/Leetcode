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
 * Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
 *
 * Solution:
 * Implementation.
 */
class Solution {
public:
    void nextPermutation(vector<int> &num) {
		if (num.size() == 0) return;
		int n = num.size();
		int i = n - 2;
		while (i >= 0 && num[i] >= num[i + 1])
			i--;
		if (i >= 0) {
			int j = i + 1;
			while (j < n && num[j] > num[i])
				j++;
			j--;
			swap(num[i], num[j]);
		}
		reverse(num.begin() + i + 1, num.end());
    }
};
int main() {
	int myints[] = {3, 2, 1};
	vector<int> ans(myints, myints + 3);
	Solution sol;
	sol.nextPermutation(ans);
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << " ";
	cout << endl;
	return 0;
}

