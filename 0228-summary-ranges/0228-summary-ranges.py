class Solution:
    def summaryRanges(self, nums):
        if not nums:
            return []

        result = []
        start = nums[0]

        for i in range(1, len(nums)):
            # Break in continuity
            if nums[i] != nums[i - 1] + 1:
                end = nums[i - 1]
                if start == end:
                    result.append(str(start))
                else:
                    result.append(f"{start}->{end}")
                start = nums[i]

        # Add the final range
        end = nums[-1]
        if start == end:
            result.append(str(start))
        else:
            result.append(f"{start}->{end}")

        return result