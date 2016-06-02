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
 * Say you have an array for which the ith element is the price of a given stock on day i.
 * If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.
 *
 * Solution:
 * Brute force
 */
class Solution {
public:
    int maxProfit(vector<int> &prices) {
		int n = prices.size();
		if (n <= 1) return 0;
		int maxProfit = 0, minPrice = prices[0];
		for (int i = 1; i < n; i++) {
			maxProfit = max(maxProfit, prices[i] - minPrice);
			minPrice = min(minPrice, prices[i]);
		}
		return maxProfit;
    }
};
int main() {
}

