# -*- coding: utf-8 -*-

class Solution(object):
    def minLength(self, s):
        """
        :type s: str
        :rtype: int
        """
        while (s.find("AB") != -1 or s.find("CD") != -1):
            s = s.replace("AB", "")
            s = s.replace("CD", "")
        return len(s)
