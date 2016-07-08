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
#include <unordered_map>
using namespace std;
#define PB push_back
#define MP make_pair
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
#define FOREACH(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
typedef long long LL;

class Solution {
public:
    vector<vector<int> > palindromePairs(vector<string>& words) {
        unordered_map<string, int> dict;
        vector<vector<int> > res;
        for (int i = 0; i < words.size(); i++) {
            string str = words[i];
            reverse(str.begin(), str.end());
            dict[str] = i;
        }
        if (dict.find("") != dict.end()) {
            for (int i = 0; i < words.size(); i++) {
                if (i == dict[""]) continue;
                if (is_palindrome(words[i])) {
                    int pairs[2] = {dict[""], i};
                    vector<int> temp(pairs, pairs + 2);
                    res.push_back(temp);
                }
            }
        }
        for (int i = 0; i < words.size(); i++) {
            for (int j = 0; j < words[i].size(); j++) {
                string strl = words[i].substr(0, j);
                string strr = words[i].substr(j, words[i].size() - j);
                if (dict.find(strl) != dict.end() && is_palindrome(strr) && dict[strl] != i) {
                    int pairs[2] = {i, dict[strl]};
                    vector<int> temp(pairs, pairs + 2);
                    res.push_back(temp);
                }
                if (dict.find(strr) != dict.end() && is_palindrome(strl) && dict[strr] != i) {
                    //cout << words[dict[strr]] << words[i] << endl;
                    int pairs[2] = {dict[strr], i};
                    vector<int> temp(pairs, pairs + 2);
                    res.push_back(temp);
                }
            }
        }
        return res;
    }

    bool is_palindrome(const string& str) {
        for (int i = 0, j = str.size() - 1; i < j; i++, j--) {
            if (str[i] != str[j]) return false;
        }
        return true;
    }

};
int main() {
    int n;
    cin >> n;
    vector<string> str(n);
    for (int i = 0; i < n; i++) {
        cin >> str[i];
        cout << str[i] << endl;
    }
    Solution sol;
    vector<vector<int> > res = sol.palindromePairs(str);
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

