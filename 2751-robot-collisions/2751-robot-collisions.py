class Solution:
    def survivedRobotsHealths(self, positions, healths, directions):
        n = len(positions)
        
        robots = sorted([(positions[i], i) for i in range(n)])
        
        stack = []  # store indices of right-moving robots
        health = healths[:]  # mutable copy
        
        for pos, i in robots:
            if directions[i] == 'R':
                stack.append(i)
            else:
                while stack and health[i] > 0:
                    j = stack[-1]
                    
                    if health[j] < health[i]:
                        health[i] -= 1
                        health[j] = 0
                        stack.pop()
                    elif health[j] == health[i]:
                        health[j] = 0
                        health[i] = 0
                        stack.pop()
                        break
                    else:
                        health[j] -= 1
                        health[i] = 0
                        break
        
        return [health[i] for i in range(n) if health[i] > 0]