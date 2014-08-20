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
 * Given two numbers represented as strings, return multiplication of the numbers as a string.
 *
 * Solution:
 * Implementation.
 *
 */
class Solution {
public:
    string multiply(string num1, string num2) {
		int n1 = num1.size(), n2 = num2.size();
		vector<int> res(n1 + n2);
		for (int i = n1 - 1; i >= 0; i--) {
			int carry = 0;
			for (int j = n2 - 1; j >= 0; j--) {
				int k = (num1[i] - '0') * (num2[j] - '0') + carry + res[i + j + 1];
				res[i + j + 1] = k % 10;
				carry = k / 10;
			}
			res[i] = carry;
		}
		string ans = "";
		for (int i = 0; i < n1 + n2; i++)
			if (ans != "" || res[i] != 0)
				ans += (char)(res[i] + '0');
		return ans == "" ? "0" : ans;
    }
};
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	string n1, n2;
	cin >> n1 >> n2;
	Solution sol;
	cout << sol.multiply(n1, n2) << endl;
	return 0;
}

