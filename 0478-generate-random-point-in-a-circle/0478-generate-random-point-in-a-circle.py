import random
import math

class Solution:

    def __init__(self, radius: float, x_center: float, y_center: float):
        self.r = radius
        self.x = x_center
        self.y = y_center

    def randPoint(self):
        theta = random.uniform(0, 2 * math.pi)
        dist = math.sqrt(random.uniform(0, 1)) * self.r
        x = self.x + dist * math.cos(theta)
        y = self.y + dist * math.sin(theta)
        return [x, y]