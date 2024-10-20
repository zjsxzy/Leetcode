#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int MOD = 998244353;
template <int mod>
struct Mod_Int {
    int x;
    Mod_Int() : x(0) {}
    Mod_Int(long long y) : x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod) {}
    static int get_mod() { return mod; }
    Mod_Int &operator+=(const Mod_Int &p) {
        if ((x += p.x) >= mod) x -= mod;
        return *this;
    }
    Mod_Int &operator-=(const Mod_Int &p) {
        if ((x += mod - p.x) >= mod) x -= mod;
        return *this;
    }
    Mod_Int &operator*=(const Mod_Int &p) {
        x = (int)(1LL * x * p.x % mod);
        return *this;
    }
    Mod_Int &operator/=(const Mod_Int &p) {
        *this *= p.inverse();
        return *this;
    }
    Mod_Int &operator++() { return *this += Mod_Int(1); }
    Mod_Int operator++(int) {
        Mod_Int tmp = *this;
        ++*this;
        return tmp;
    }
    Mod_Int &operator--() { return *this -= Mod_Int(1); }
    Mod_Int operator--(int) {
        Mod_Int tmp = *this;
        --*this;
        return tmp;
    }
    Mod_Int operator-() const { return Mod_Int(-x); }
    Mod_Int operator+(const Mod_Int &p) const { return Mod_Int(*this) += p; }
    Mod_Int operator-(const Mod_Int &p) const { return Mod_Int(*this) -= p; }
    Mod_Int operator*(const Mod_Int &p) const { return Mod_Int(*this) *= p; }
    Mod_Int operator/(const Mod_Int &p) const { return Mod_Int(*this) /= p; }
    bool operator==(const Mod_Int &p) const { return x == p.x; }
    bool operator!=(const Mod_Int &p) const { return x != p.x; }
    Mod_Int inverse() const {
        assert(*this != Mod_Int(0));
        return pow(mod - 2);
    }
    Mod_Int pow(long long k) const {
        Mod_Int now = *this, ret = 1;
        for (; k > 0; k >>= 1, now *= now) {
            if (k & 1) ret *= now;
        }
        return ret;
    }
    friend ostream &operator<<(ostream &os, const Mod_Int &p) { return os << p.x; }
    friend istream &operator>>(istream &is, Mod_Int &p) {
        long long a;
        is >> a;
        p = Mod_Int<mod>(a);
        return is;
    }
};
using mint = Mod_Int<MOD>;

const int B = 2333;
class Solution {
public:
    vector<bool> findAnswer(vector<int>& parent, string s) {
        int n = parent.size();
        g.assign(n, {});
        for (int i = 1; i < n; i++) {
            g[parent[i]].push_back(i);
        }
        for (int i = 0; i < n; i++) {
            sort(g[i].begin(), g[i].end());
        }
        dfn.resize(n);
        siz.resize(n);
        S = s;
        seq = "";
        dfs(0, -1);

        Hash(seq);
        vector<bool> ans(n);
        for (int i = 0; i < n; i++) {
            ans[i] = query(dfn[i], dfn[i] + siz[i] - 1);
        }
        return ans;
    }

    void dfs(int u, int p) {
        dfn[u] = seq.size();

        for (auto v: g[u]) {
            if (v != p) {
                dfs(v, u);
                siz[u] += siz[v];
            }
        }
        siz[u]++;
        seq += S[u];
    }

    void Hash(string& s) {
        int n = s.size();
        bs.resize(n + 1); hash.resize(n + 1); rhash.resize(n + 1);
        bs[0] = 1;
        for (int i = 1; i <= n; i++) {
            bs[i] = bs[i - 1] * B;
        }
        for (int i = 0; i < n; i++) {
            hash[i + 1] = hash[i] * B + s[i];
            rhash[i + 1] = rhash[i] * B + s[n - i - 1];
        }
    }

    bool query(int l, int r) {
        int n = seq.size();
        l++, r++;
        mint A = hash[r] - hash[l - 1] * bs[r - l + 1];
        int L = n - r + 1, R = n - l + 1;
        mint B = rhash[R] - rhash[L - 1] * bs[R - L + 1];
        return A == B;
    }

    vector<mint> hash, rhash, bs;
    string S, seq;
    vector<vector<int>> g;
    vector<int> dfn, siz;
};

void solve() {
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int ts = 1;
    // cin >> ts;
    for (int t = 1; t <= ts; t++) {
       solve();
    }
    return 0;
}

