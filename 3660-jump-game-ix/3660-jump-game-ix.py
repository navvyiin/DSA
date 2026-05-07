class Solution:
    def maxValue(self, nums):
        n = len(nums)

        prefix_max = [0] * n
        suffix_min = [0] * n

        prefix_max[0] = nums[0]
        for i in range(1, n):
            prefix_max[i] = max(prefix_max[i - 1], nums[i])

        suffix_min[n - 1] = nums[n - 1]
        for i in range(n - 2, -1, -1):
            suffix_min[i] = min(suffix_min[i + 1], nums[i])

        ans = [0] * n

        start = 0

        for i in range(n - 1):
            # Split components when there is NO inversion crossing
            if prefix_max[i] <= suffix_min[i + 1]:
                component_max = max(nums[start:i + 1])

                for j in range(start, i + 1):
                    ans[j] = component_max

                start = i + 1

        component_max = max(nums[start:])

        for j in range(start, n):
            ans[j] = component_max

        return ans