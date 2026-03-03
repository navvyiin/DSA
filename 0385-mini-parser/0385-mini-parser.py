# """
# This is the interface that allows for creating nested lists.
# You should not implement it, or speculate about its implementation.
#
# class NestedInteger:
#     def __init__(self, value=None):
#         """
#         If value is not specified, initializes an empty list.
#         Otherwise initializes a single integer equal to value.
#         """
#
#     def isInteger(self):
#         """
#         @return True if this NestedInteger holds a single integer.
#         """
#
#     def add(self, elem):
#         """
#         Set this NestedInteger to hold a nested list and adds elem to it.
#         """
#
#     def setInteger(self, value):
#         """
#         Set this NestedInteger to hold a single integer equal to value.
#         """
#
#     def getInteger(self):
#         """
#         @return the single integer that this NestedInteger holds.
#         """
#
#     def getList(self):
#         """
#         @return the nested list that this NestedInteger holds.
#         """
# """

class Solution:
    def deserialize(self, s: str) -> 'NestedInteger':
        # If it's just a single integer
        if s[0] != '[':
            return NestedInteger(int(s))
        
        stack = []
        num = 0
        sign = 1
        current = None
        
        for i, char in enumerate(s):
            if char == '[':
                if current is not None:
                    stack.append(current)
                current = NestedInteger()
            
            elif char == '-':
                sign = -1
            
            elif char.isdigit():
                num = num * 10 + int(char)
            
            elif char in ',]':
                # If previous character was digit, we completed a number
                if s[i - 1].isdigit():
                    current.add(NestedInteger(sign * num))
                
                num = 0
                sign = 1
                
                if char == ']' and stack:
                    parent = stack.pop()
                    parent.add(current)
                    current = parent
        
        return current