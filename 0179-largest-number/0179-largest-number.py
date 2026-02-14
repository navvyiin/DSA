from functools import cmp_to_key

class Solution:
    def largestNumber(self, nums):
        # Convert integers to strings
        nums = list(map(str, nums))
        
        # Custom comparator
        def compare(a, b):
            if a + b > b + a:
                return -1   # a should come before b
            elif a + b < b + a:
                return 1    # b should come before a
            else:
                return 0
        
        # Sort using the custom comparator
        nums.sort(key=cmp_to_key(compare))
        
        # Edge case: when the highest number is "0"
        if nums[0] == "0":
            return "0"
        
        # Join to form the largest number
        return "".join(nums)