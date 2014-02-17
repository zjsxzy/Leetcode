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
 * Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.
 *
 * Solution:
 * Implementation.
 */
class Solution {
public:
    bool isPalindrome(string s) {
		int n = s.size();
		int l = 0, r = n - 1;
		while (true) {
			while (l < r && !isLetterOrDigit(s[l]))
				l++;
			while (l < r && !isLetterOrDigit(s[r]))
				r--;
			if (l >= r) return true;
			if (tolower(s[l]) != tolower(s[r])) return false;
			l++;
			r--;
		}
    }
	bool isLetterOrDigit(char ch) {
		return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9');
	}
};
int main() {
}

