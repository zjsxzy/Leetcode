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

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        int n = words.size();
        if (n == 0) {
            return res;
        }
        int len = words[0].size();
        int m = s.size();

        map<string, int> ori_words;
        for (auto w : words) {
            ori_words[w]++;
        }

        // 枚举起点
        for (int i = 0; i < len; i++) {
            map<string, int> cnt;
            int tot = 0;
            for (int l = i, r = i; l + len * n <= m; ) {
                bool flag = false;
                string sub;
                while (r < m && tot < n) {
                    sub = s.substr(r, len);
                    // 子串不在words列表中
                    if (ori_words.find(sub) == ori_words.end()) {
                        flag = true;
                        break;
                    }
                    
                    cnt[sub]++;
                    // 子串数量超过words中的数量
                    if (cnt[sub] > ori_words[sub]) {
                        cnt[sub]--;
                        break;
                    }
                    tot++;
                    r += len;
                    
                }

                if (tot == n) {
                    res.push_back(l);
                }

                if (ori_words.find(sub) == ori_words.end()) { // sub不在words列表中，l可以直接移动到r+len                
                    r += len;
                    l = r;
                    tot = 0;
                    cnt.clear();
                } else { // 子串左区间向右移动一个单位
                    sub = s.substr(l, len);
                    cnt[sub]--;
                    tot--;
                    l += len;
                }
                
            }
        }
        return res;
    }
};