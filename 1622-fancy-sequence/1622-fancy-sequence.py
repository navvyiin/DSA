class Fancy:

    def __init__(self):
        self.MOD = 10**9 + 7
        self.seq = []
        self.a = 1
        self.b = 0

    def modinv(self, x):
        return pow(x, self.MOD - 2, self.MOD)

    def append(self, val: int) -> None:
        normalized = (val - self.b) % self.MOD
        normalized = normalized * self.modinv(self.a) % self.MOD
        self.seq.append(normalized)

    def addAll(self, inc: int) -> None:
        self.b = (self.b + inc) % self.MOD

    def multAll(self, m: int) -> None:
        self.a = (self.a * m) % self.MOD
        self.b = (self.b * m) % self.MOD

    def getIndex(self, idx: int) -> int:
        if idx >= len(self.seq):
            return -1
        return (self.seq[idx] * self.a + self.b) % self.MOD