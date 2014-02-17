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
 * Implement atoi to convert a string to an integer.
 *
 * Solution:
 * Implementation.
 */
class Solution {
public:
    int atoi(const char *str) {
		int index = 0;
		int len = strlen(str);
		while (index < len && str[index] == ' ')
			index++;
		bool positive = true;
		if (index < len && (str[index] == '+' || str[index] == '-')) {
			positive = str[index] == '+';
			index++;
		}
		int num = 0;
		bool overflow = false;
		while (!overflow && index < len && (str[index] >= '0' && str[index] <= '9')) {
			int d = str[index] - '0';
			if (num > INT_MAX / 10) {
				overflow = true;
			}
			num *= 10;
			if (num > INT_MAX - d) {
				overflow = true;
			}
			num += d;
			index++;
		}
		if (overflow)
			return positive ? INT_MAX : INT_MIN;
		else return positive ? num : -num;
    }
};
int main() {
}

