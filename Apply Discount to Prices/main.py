# -*- coding: utf-8 -*-

class Solution:
    def discountPrices(self, sentence: str, discount: int) -> str:
        res = []
        sentence = sentence.split(' ')
        n = len(sentence)
        for i in range(n):
            s = sentence[i]
            if (s.startswith('$')):
                if len(s[1:]) > 0:
                    flag = True
                    m = len(s)
                    for i in range(1, m):
                        if s[i] < '0' or s[i] > '9':
                            flag = False
                            break
                    if flag:
                        p = float(s[1:])
                        p = p * (100. - discount) / 100
                        res.append('$%.2f'%(p))
                    else:
                        res.append(s)
                else:
                    res.append(s)
            else:
                res.append(s)
        return ' '.join(res)
