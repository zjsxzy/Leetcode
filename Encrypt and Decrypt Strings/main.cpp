#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

class Encrypter {
public:
    int n;
    map<char, string> conv;
    map<string, vector<char>> rev;
    map<string, int> cnt;
    Encrypter(vector<char>& keys, vector<string>& values, vector<string>& dictionary) {
        n = keys.size();
        for (int i = 0; i < n; i++) {
            conv[keys[i]] = values[i];
            rev[values[i]].push_back(keys[i]);
        }
        for (auto d: dictionary) {
            cnt[encrypt(d)]++;
        }
    }

    string encrypt(string word1) {
        string res;
        for (auto c: word1) {
            res += conv[c];
        }
        return res;
    }

    int decrypt(string word2) {
        if (cnt.find(word2) == cnt.end()) return 0;
        return cnt[word2];
    }
};

/**
 * Your Encrypter object will be instantiated and called as such:
 * Encrypter* obj = new Encrypter(keys, values, dictionary);
 * string param_1 = obj->encrypt(word1);
 * int param_2 = obj->decrypt(word2);
 */
void solve() {
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    solve();
    return 0;
}

