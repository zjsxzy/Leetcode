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
 * Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
 *
 * Solution:
 * Use two stacks to maintain the elements and mins.
 *
 */
class MinStack {
public:
	stack<int> st, mins;
    void push(int x) {
		st.push(x);
		if (mins.empty() || x <= mins.top()) {
			mins.push(x);
		}
    }

    void pop() {
		int x = st.top();
		st.pop();
		if (x == mins.top()) {
			mins.pop();
		}
    }

    int top() {
		return st.top();
    }

    int getMin() {
		return mins.top();
    }
};
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	MinStack st;
	st.push(512);
	st.push(-1024);
	st.push(-1024);
	st.push(512);
	st.pop();
	cout << st.getMin() << endl;
	st.pop();
	cout << st.getMin() << endl;
	st.pop();
	cout << st.getMin() << endl;
	return 0;
}

