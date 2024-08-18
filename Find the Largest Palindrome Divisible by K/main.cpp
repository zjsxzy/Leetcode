#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class Solution {
public:
    string largestPalindrome(int n, int k) {
        string s;
        if (k == 1 || k == 3 || k == 9) {
            for (int i = 0; i < n; i++) s += '9';
            return s;
        }
        if (k == 2) {
            s = "8";
            for (int i = 0; i < n - 2; i++) s += '9';
            if (n > 1) s += '8';
            return s;
        }
        if (k == 5) {
            s = "5";
            for (int i = 0; i < n - 2; i++) s += '9';
            if (n > 1) s += '5';
            return s;
        }
        if (k == 4) {
            if (n <= 4) return find(n, k);
            else {
                string t = find(4, k);
                s = t.substr(0, 2);
                for (int i = 0; i < n - 4; i++) s += '9';
                s += t.substr(2, 2);
                return s;
            }
        }
        if (k == 8) {
            if (n <= 6) return find(n, k);
            else {
                string t = find(6, k);
                s = t.substr(0, 3);
                for (int i = 0; i < n - 6; i++) s += '9';
                s += t.substr(2, 3);
                return s;
            }
        }
        if (k == 6) {
            if (n <= 6) return find(n, k);
            else {
                s = "89";
                n -= 4;
                if (n & 1) {
                    for (int i = 0; i < n / 2; i++) s += '9';
                    s += '8';
                    for (int i = 0; i < n / 2; i++) s += '9';
                } else {
                    n -= 2;
                    for (int i = 0; i < n / 2; i++) s += '9';
                    s += "77";
                    for (int i = 0; i < n / 2; i++) s += '9';
                }
                s += "98";
                return s;
            }
        }
        if (k == 7) {
            if (n <= 6) return find(n, k);
            if (n % 6 == 0) {
                for (int i = 0; i < n; i++) s += '9';
                return s;
            } else {
                vector<string> add = {"", "7", "77", "959", "9779", "99799", "999999", "9994999", "99944999", "999969999", "9999449999", "99999499999"};
                int a = n / 6, b = n % 6 + (a & 1) * 6;
                for (int i = 0; i < a / 2; i++) s += "999999";
                s += add[b];
                for (int i = 0; i < a / 2; i++) s += "999999";
                return s;
            }
        }
        return "";
    }

    string find(int n, int k) {
        int m = 1;
        for (int i = 0; i < n; i++) m *= 10;
        int i = m - 1;
        while (i) {
            string t = to_string(i);
            if (palindrome(t) && i % k == 0) {
                return t;
            }
            i--;
        }
        return "";
    }

    bool palindrome(string s) {
        int n = s.size();
        for (int i = 0; i < n / 2; i++) {
            if (s[i] != s[n - i - 1]) return false;
        }
        return true;
    }
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

