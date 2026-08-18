class Solution:
    def largestInteger(self, nums, k):
        n = len(nums)
        count = {}

        for i in range(n - k + 1):
            window = set(nums[i:i + k])

            for x in window:
                count[x] = count.get(x, 0) + 1

        ans = -1

        for x, freq in count.items():
            if freq == 1:
                ans = max(ans, x)

        return ans