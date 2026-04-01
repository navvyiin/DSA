class Solution:
    def survivedRobotsHealths(self, positions, healths, directions):
        idx = list(range(len(positions)))
        idx.sort(key=positions.__getitem__)
        
        stack = []
        health = healths
        
        for i in idx:
            if directions[i] == 'R':
                stack.append(i)
            else:
                while stack and health[i]:
                    j = stack[-1]
                    
                    if health[j] < health[i]:
                        health[i] -= 1
                        health[j] = 0
                        stack.pop()
                    elif health[j] > health[i]:
                        health[j] -= 1
                        health[i] = 0
                    else:
                        health[j] = 0
                        health[i] = 0
                        stack.pop()
        
        return [h for h in health if h]