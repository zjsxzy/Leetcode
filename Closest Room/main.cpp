#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

struct Event {
    int type; // 事件的类型，0 表示房间，1 表示询问
    int size; // 房间的 size 或者询问的 minSize
    int id; // 房间的 roomId 或者询问的 preferred
    int origin; // 房间在数组 room 中的原始编号或者询问在数组 queries 中的原始编号

    Event(int _type, int _size, int _id, int _origin): type(_type), size(_size), id(_id), origin(_origin) {}

    // 自定义比较函数，按照事件的 size 降序排序
    // 如果 size 相同，优先考虑房间
    bool operator< (const Event& that) const {
        return size > that.size || (size == that.size && type < that.type);
    }
};
class Solution {
public:
    vector<int> closestRoom(vector<vector<int>>& rooms, vector<vector<int>>& queries) {
        int n = rooms.size(), m = queries.size();
        vector<Event> events;
        for (int i = 0; i < n; i++) {
            events.emplace_back(0, rooms[i][1], rooms[i][0], i);
        }
        for (int i = 0; i < m; i++) {
            events.emplace_back(1, queries[i][1], queries[i][0], i);
        }
        sort(events.begin(), events.end());

        vector<int> res(m, -1);
        set<int> st;
        for (auto &event: events) {
            if (event.type == 0) {
                st.insert(event.id);
            } else {
                auto it = st.lower_bound(event.id);
                int dist = INT_MAX;
                if (it != st.end() && *it - event.id < INT_MAX) {
                    dist = *it - event.id;
                    res[event.origin] = *it;
                }
                if (it != st.begin()) {
                    it--;
                    if (event.id - *it <= dist) {
                        res[event.origin] = *it;
                    }
                }
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

