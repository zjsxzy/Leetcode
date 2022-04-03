# -*- coding: utf-8 -*-

class Solution(object):
    def convertTime(self, current, correct):
        """
        :type current: str
        :type correct: str
        :rtype: int
        """
        h, m = current.split(':')
        hh, mm = correct.split(':')
        dh = int(hh) - int(h)
        dm = int(mm) - int(m)
        if dm < 0:
            dm += 60
            dh -= 1
        res = 0
        while (dm >= 60):
            res += 1
            dm -= 60
        while (dm >= 15):
            res += 1
            dm -= 15
        while (dm >= 5):
            res += 1
            dm -= 5
        print(dh, res, dm)
        return dh + res + dm
