class Robot:

    def __init__(self, width: int, height: int):
        self.w = width
        self.h = height
        self.perim = 2 * (width + height) - 4
        self.pos = 0
        self.moved = False  # track if any step has happened

    def step(self, num: int) -> None:
        self.pos = (self.pos + num) % self.perim
        if num > 0:
            self.moved = True

    def getPos(self):
        p = self.pos
        
        if p < self.w:
            return [p, 0]
        p -= self.w
        
        if p < self.h - 1:
            return [self.w - 1, p + 1]
        p -= (self.h - 1)
        
        if p < self.w - 1:
            return [self.w - 2 - p, self.h - 1]
        p -= (self.w - 1)
        
        return [0, self.h - 2 - p]

    def getDir(self):
        p = self.pos
        
        if p == 0:
            return "East" if not self.moved else "South"
        
        if p < self.w:
            return "East"
        if p < self.w + self.h - 1:
            return "North"
        if p < self.w + self.h - 1 + self.w - 1:
            return "West"
        return "South"