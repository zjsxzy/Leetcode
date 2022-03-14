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

class ParkingSystem {
public:
    int big, medium, small;

    ParkingSystem(int big, int medium, int small) {
        this->big = big;
        this->medium = medium;
        this->small = small;
    }

    bool addCar(int carType) {
        if (carType == 1) {
            if (this->big > 0) {
                this->big--;
                return true;
            } else {
                return false;
            }
        } else if (carType == 2) {
            if (this->medium > 0) {
                this->medium--;
                return true;
            } else {
                return false;
            }
        } else if (carType == 3) {
            if (this->small > 0) {
                this->small--;
                return true;
            } else {
                return false;
            }
        }
        return false;
    }
};

int main() {
    ParkingSystem parkingSystem = ParkingSystem(1, 1, 0);
    return 0;
}

