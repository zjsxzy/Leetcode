class Solution {
public:
    int distanceTraveled(int mainTank, int additionalTank) {
        int x = mainTank, y = additionalTank, res = 0, curr = 0;
        while (x > 0) {
            curr++;
            res += 10;
            x--;
            if (curr == 5 && y > 0) {
                y--;
                x++;
                curr = 0;
            }
        }
        return res;
    }
};
