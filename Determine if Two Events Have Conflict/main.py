# -*- coding: utf-8 -*-

class Solution(object):
    def calc(self, s):
        # print(s)
        l = s.split(':')
        h = int(l[0])
        m = int(l[1])
        return h * 60 + m
    def haveConflict(self, event1, event2):
        """
        :type event1: List[str]
        :type event2: List[str]
        :rtype: bool
        """
        st1, ed1 = self.calc(event1[0]), self.calc(event1[1])
        st2, ed2 = self.calc(event2[0]), self.calc(event2[1])
        # print(st1, ed1)
        # print(st2, ed2)
        if (ed1 < st2) or (ed2 < st1):
            return False
        return True

