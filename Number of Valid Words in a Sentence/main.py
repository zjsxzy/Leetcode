# -*- coding: utf-8 -*-

import string

def check(word):
    for i in range(10):
        if word.find(str(i)) >= 0:
            return False
    if word.count('-') > 1:
        return False
    p = word.find('-')
    n = len(word)
    if p == 0 or p == n - 1:
        return False
    if p > 0:
        if not word[p - 1] in string.ascii_lowercase or not word[p + 1] in string.ascii_lowercase:
            return False
    p = word.find(',')
    if p >= 0 and p != n - 1:
        return False
    p = word.find('.')
    if p >= 0 and p != n - 1:
        return False
    p = word.find('!')
    if p >= 0 and p != n - 1:
        return False
    return True

class Solution(object):

    def countValidWords(self, sentence):
        """
        :type sentence: str
        :rtype: int
        """
        words = sentence.split(' ')
        tot = 0
        for w in words:
            if check(w):
                # print(w)
                tot += 1
        return tot



