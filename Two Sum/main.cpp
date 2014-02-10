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
 * Given an array of integers, find two numbers such that they add up to a specific target number.
 *
 * Solution:
 * Hash
 */
class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
		int n = numbers.size();
		map<int, int> mp;
		vector<int> ans;
		for (int i = 0; i < n; i++) {
			if (mp.find(target - numbers[i]) != mp.end()) {
				ans.push_back(mp[target - numbers[i]] + 1);
				ans.push_back(i + 1);
				return ans;
			}
			mp[numbers[i]] = i;
		}
		return ans;
    }
};
int main() {
}

