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

class Solution {
public:

    pair<int, int> get_hour_minute(string t) {
        int k = t.find(':');
        return make_pair(stoi(t.substr(0, k)), stoi(t.substr(k+1, 5)));
    }

    vector<string> alertNames(vector<string>& keyName, vector<string>& keyTime) {
        map<string, vector<pair<int, int> > > time;
        vector<string> alert;
        int n = keyName.size();
        for (int i = 0; i < n; i++) {
            string name = keyName[i];
            if (time.find(name) == time.end()) {
                vector<pair<int, int> > vec;
                time[name] = vec;
            }
            time[name].push_back(get_hour_minute(keyTime[i]));
        }
        for (auto it = time.begin(); it != time.end(); it++) {
            cout << it->first << endl;
            cout << it->second.size() << endl;
            sort(it->second.begin(), it->second.end());
            int m = it->second.size();
            if (m < 3) {
                continue;
            } else {
                for (int i = 0; i < m - 2; i++) {
                    pair<int, int> first = it->second[i], last = it->second[i + 2];
                    if (last.first - first.first == 0) {
                        alert.push_back(it->first);
                        break;
                    } else if ((last.first - first.first == 1) && (last.second <= first.second)) {
                        alert.push_back(it->first);
                        break;
                    }
                }
            }
        }
        sort(alert.begin(), alert.end());
        return alert;
    }
};

int main() {
    Solution sol;
    vector<string> keyname;
    keyname.push_back("a"); keyname.push_back("a"), keyname.push_back("a");
    vector<string> keytime;
    keytime.push_back("12:00"); keytime.push_back("12:01"); keytime.push_back("12:59");
    sol.alertNames(keyname, keytime);
    return 0;
}

