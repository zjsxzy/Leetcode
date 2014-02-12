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
 * There are N gas stations along a circular route, where the amount of gas at station i is gas[i].
 * You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1). You begin the journey with an empty tank at one of the gas stations.
 * Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.
 *
 * Solution:
 * Find the point that the prefix after which is always nonnegtive. The point is kth point + 1, which k has the minimum prefix.
 */
class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
		int n = gas.size();
		int prefix = 0, idx = 0, lowest = 0;
		for (int i = 0; i < n; i++) {
			int diff = gas[i] - cost[i];
			prefix += diff;
			if (prefix < lowest) {
				lowest = prefix;
				idx = i + 1;
			}
		}
		return prefix >= 0 ? idx : -1;
    }
};
int main() {
}

