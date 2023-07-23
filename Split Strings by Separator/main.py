# -*- coding: utf-8 -*-

class Solution(object):
    def splitWordsBySeparator(self, words, separator):
        """
        :type words: List[str]
        :type separator: str
        :rtype: List[str]
        """
        s = separator.join(words)
        res = s.split(separator)
        res = [x for x in res if x != '']
        return res
