#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) return "0";
        string fraction;
        if (numerator < 0 ^ denominator < 0) {
            fraction.append("-");
        }
        long long num = abs((long long)numerator);
        long long den = abs((long long)denominator);
        // cout << fraction << " " << numerator << " " << denominator << endl;
        fraction.append(to_string(num / den));
        long long remainder = num % den;
        if (remainder == 0) {
            return fraction;
        }
        fraction.append(".");
        map<int, int> mp;
        while (remainder != 0) {
            if (mp.find(remainder) != mp.end()) {
                fraction.insert(mp[remainder], "(");
                fraction.append(")");
                break;
            }
            mp[remainder] = fraction.size();
            remainder *= 10;
            fraction.append(to_string(remainder / den));
            remainder %= den;
        }
        return fraction;
    }
};

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    solve();
    return 0;
}

