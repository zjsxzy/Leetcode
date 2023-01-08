#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class Solution {
public:
    int findCrossingTime(int n, int K, vector<vector<int>>& time) {

        // 所有工人按效率从高到低排序
        // 因为不需要输出和工人下标有关系的东西，排序后下标的顺序就是效率顺序，比较方便
        for (int i = 0; i < K; i++) time[i].push_back(i);
        sort(time.begin(), time.end(), [](vector<int>& a, vector<int>& b) {
            int L = a[0] + a[2], R = b[0] + b[2];
            if (L != R) return L < R;
            else return a[4] < b[4];
        });

        // now：桥接下来的可用时间
        int now = 0;
        // 用大根堆模拟效率低的工人先过桥
        // left：左边目前有哪些工人等待过桥
        // right：右边目前有哪些工人等待过桥
        priority_queue<int> left, right;
        // 用小根堆模拟哪些工人先放好箱子
        // pL：左边有哪些工人正在放箱子
        // pR：右边有哪些工人正在拿箱子
        // 这个 pair 中，第一个数是工人放（拿）好箱子的时间，第二个数是工人的编号
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pL, pR;
        // 一开始所有工人都在左边等待
        for (int i = 0; i < K; i++) left.push(i);
        // 模拟搬运过程
        while (true) {
            // 桥接下来的可用时间到来前，哪些工人已经放好箱子了，把他们加入等待队列
            while (!pL.empty()) {
                pair<int, int> p = pL.top();
                if (p.first > now) break;
                pL.pop();
                left.push(p.second);
            }
            while (!pR.empty()) {
                pair<int, int> p = pR.top();
                if (p.first > now) break;
                pR.pop();
                right.push(p.second);
            }

            // 判断桥接下来的可用时间到来后，左右是否有人可以过桥
            bool leftGo = n > 0 && !left.empty();
            bool rightGo = !right.empty();
            if (!leftGo && !rightGo) {
                // 左右都没有人可以过桥，直接快进到下一个有人过桥的时间
                int x = 1e9;
                if (!pL.empty()) x = min(x, pL.top().first);
                if (!pR.empty()) x = min(x, pR.top().first);
                now = x;
                continue;
            }

            if (rightGo) {
                // 右边有人要过桥
                int x = right.top(); right.pop();
                now += time[x][2];
                // 已经没有箱子可以搬了，而且右边也没人等着过桥，可以返回答案
                if (n == 0 && right.empty() && pR.empty()) return now;
                // 把过桥的人加入放箱子的优先队列
                pL.push({now + time[x][3], x});
            } else {
                // 左边有人要过桥
                int x = left.top(); left.pop();
                now += time[x][0];
                // 拿走一个箱子
                n--;
                // 把过桥的人加入拿箱子的优先队列
                pR.push({now + time[x][1], x});
            }
        }
    }
};

void solve() {
}

int main() {
    int ts = 1;
    // cin >> ts;
    for (int t = 1; t <= ts; t++) {
        solve();
    }
    return 0;
}

