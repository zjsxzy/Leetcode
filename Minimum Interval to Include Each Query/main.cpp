#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

struct Event {
    // 事件的类型，0 表示左端点，1 表示询问，2 表示右端点
    int type;
    // 事件的位置
    int pos;
    // 事件的额外参数
    // 如果是 0 左端点事件，那么 para 记录右端点的位置
    // 如果是 1 询问事件，那么 para 记录它是第几个询问，以便于返回答案数组
    // 如果是 2 右端点事件，那么 para 记录左端点的位置
    int para;

    Event(int _type, int _pos, int para): type(_type), pos(_pos), para(para) {}

    // 自定义比较函数，按照事件的位置升序排序
    // 如果位置相同，按照左端点、询问、右端点的顺序排序
    bool operator< (const Event& that) const {
        return pos < that.pos || (pos == that.pos && type < that.type);
    }
};
class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        int n = intervals.size(), m = queries.size();
        vector<Event> events;
        for (int i = 0; i < m; i++) {
            events.emplace_back(1, queries[i], i);
        }
        for (int i = 0; i < n; i++) {
            events.emplace_back(0, intervals[i][0], intervals[i][1]);
            events.emplace_back(2, intervals[i][1], intervals[i][0]);
        }
        sort(events.begin(), events.end());
        vector<int> res(m, -1);
        multiset<int> seg;
        for (auto &event : events) {
            if (event.type == 0) { // 左端点
                seg.insert(event.para - event.pos + 1);
            } else if (event.type == 1) { // 查询
                if (!seg.empty()) {
                    res[event.para] = *seg.begin();
                }
            } else if (event.type == 2) { // 右端点
                int len = event.pos - event.para + 1;
                auto it = seg.find(len);
                seg.erase(it);
            }
        }
        return res;
    }
};

void solve() {
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    solve();
    return 0;
}

