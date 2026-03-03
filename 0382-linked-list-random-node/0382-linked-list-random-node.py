import random

class Solution:

    def __init__(self, head):
        self.head = head

    def getRandom(self) -> int:
        current = self.head
        chosen_value = None
        count = 0

        while current:
            count += 1
            
            # Replace with probability 1/count
            if random.randint(1, count) == 1:
                chosen_value = current.val
            
            current = current.next

        return chosen_value