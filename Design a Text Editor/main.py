# -*- coding: utf-8 -*-

class TextEditor:
    s = ""
    pos = 0

    def __init__(self):
        self.s = ""
        self.pos = 0

    def addText(self, text: str) -> None:
        if len(self.s) > 0:
            self.s = self.s[:self.pos] + text + self.s[self.pos:]
            self.pos += len(text)
        else:
            self.s += text
            self.pos = len(text)

    def deleteText(self, k: int) -> int:
        if self.pos >= k:
            self.s = self.s[: self.pos-k] + self.s[self.pos:]
            self.pos -= k
            return k
        else:
            t = self.pos
            self.s = self.s[self.pos:]
            self.pos = 0
            return t

    def cursorLeft(self, k: int) -> str:
        np = max(0, self.pos - k)
        self.pos = int(np)
        d = min(10, self.pos)
        return self.s[self.pos - d: self.pos]

    def cursorRight(self, k: int) -> str:
        n = len(self.s)
        np = min(n, self.pos + k)
        self.pos = np
        d = min(10, self.pos)
        return self.s[self.pos - d: self.pos]


# Your TextEditor object will be instantiated and called as such:
# obj = TextEditor()
# obj.addText(text)
# param_2 = obj.deleteText(k)
# param_3 = obj.cursorLeft(k)
# param_4 = obj.cursorRight(k)
