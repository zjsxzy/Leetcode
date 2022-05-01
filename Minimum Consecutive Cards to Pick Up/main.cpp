class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        int n = cards.size();
        map<int, vector<int>> mp;
        for (int i = 0; i < n; i++) {
            mp[cards[i]].push_back(i);
        }
        int res = INT_MAX;
        for (auto& [k, v]: mp) {
            if (v.size() > 1) {
                for (int i = 1; i < v.size(); i++) {
                    res = min(res, v[i] - v[i - 1] + 1);
                }
            }
        }
        if (res == INT_MAX) res = -1;
        return res;
    }
};
