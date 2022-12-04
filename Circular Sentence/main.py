# -*- coding: utf-8 -*-

class Solution(object):
    def isCircularSentence(self, sentence):
        """
        :type sentence: str
        :rtype: bool
        """
        words = sentence.split(' ')
        n = len(words)
        if words[0][0] != words[-1][-1]:
            return False
        for i in range(n - 1):
            if words[i][-1] != words[i + 1][0]:
                return False
        return True
