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
 * Returns a pointer to the first occurrence of needle in haystack, or null if needle is not part of haystack.
 *
 * Solution:
 * Brute force (or KMP).
 */
class Solution {
public:
    char *strStr(char *haystack, char *needle) {
		if (haystack == NULL || needle == NULL) return NULL;
		int lh = strlen(haystack), ln = strlen(needle);
		for (int i = 0; i + ln <= lh; i++) {
			int j = 0;
			for (; j < ln; j++) {
				if (haystack[i + j] != needle[j]) break;
			}
			if (j == ln) return haystack + i;
		}
		return NULL;
    }
};
int main() {
}

