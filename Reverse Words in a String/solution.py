"""
Description:
Given an input string, reverse the string word by word.

Solution:
Brute force.
"""
class Solution:
    # @param s, a string
    # @return a string
    def reverseWords(self, s):
        str = s.split()
        str.reverse()
        return ' '.join(str)

if __name__ == "__main__":
    sol = Solution()
    print sol.reverseWords(" ")