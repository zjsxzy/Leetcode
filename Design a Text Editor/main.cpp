#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class TextEditor {
public:
    string s;
    int pos = 0;

    TextEditor() {}

    void addText(string text) {
        s.insert(pos, text);
        pos += (int)text.length();
    }

    int deleteText(int k) {
        int p = min(k, pos);
        s.erase(max(pos - k, 0), p);
        pos -= p;
        return p;
    }

    string cursorLeft(int k) {
        int np = max(0, pos - k);
        pos = np;
        int d = min(10, pos);
        return s.substr(pos - d, d);
    }

    string cursorRight(int k) {
        int len = s.size();
        int np = min(len, pos + k);
        pos = np;
        int d = min(10, pos);
        return s.substr(pos - d, d);
    }
};

/**
 * Your TextEditor object will be instantiated and called as such:
 * TextEditor* obj = new TextEditor();
 * obj->addText(text);
 * int param_2 = obj->deleteText(k);
 * string param_3 = obj->cursorLeft(k);
 * string param_4 = obj->cursorRight(k);
 */

void solve() {
}

int main() {
#ifndef ONLINE_JUDGE
   freopen("in.txt", "r", stdin);
#endif
   int ts = 1;
   // cin >> ts;
   for (int t = 1; t <= ts; t++) {
       solve();
   }
   return 0;
}

