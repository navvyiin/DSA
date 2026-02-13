class Solution:
    def findPeakElement(self, nums: list[int]) -> int:
        left, right = 0, len(nums) - 1

        while left < right:
            mid = (left + right) // 2

            if nums[mid] > nums[mid + 1]:
                # Peak is in left half (including mid)
                right = mid
            else:
                # Peak is in right half
                left = mid + 1

        return left