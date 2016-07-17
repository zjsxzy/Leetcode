#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int n, m;
    int numIslands(vector<vector<char> >& grid) {
        n = grid.size();
        if (n == 0) return 0;
        m = grid[0].size();
        if (m == 0) return 0;
        parent.resize(n * m);
        for (int i = 0; i < n * m; i++) parent[i] = i;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '0') continue;
                int index = i * m + j;
                if (i - 1 >= 0 && grid[i - 1][j] == '1') {
                    merge(index, (i - 1) * m + j);
                }
                if (j - 1 >= 0 && grid[i][j - 1] == '1') {
                    merge(index, i * m + (j - 1));
                }
                if (i + 1 < n && grid[i + 1][j] == '1') {
                    merge(index, (i + 1) * m + j);
                }
                if (j + 1 < m && grid[i][j + 1] == '1') {
                    merge(index, i * m + (j + 1));
                }
            }
        }
        int res = 0;
        for (int i = 0; i < n * m; i++) {
            res += (find(i) == i && grid[i / m][i % m] == '1');
        }
        return res;
    }

    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    void merge(int x, int y) {
        //cout << x / m << " " << x % m << " " << y / m << " " << y % m << endl;
        x = find(x);
        y = find(y);

        if (x == y) return;
        parent[x] = y;
    }

    vector<int> parent;
};

int n, m;
int main() {
    cin >> n >> m;
    vector<vector<char> > grid;
    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        vector<char> temp(str.begin(), str.end());
        grid.push_back(temp);
    }
    Solution sol;
    int res = sol.numIslands(grid);
    cout << res << endl;
    return 0;
}
