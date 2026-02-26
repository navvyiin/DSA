class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        vector<long long> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }
        return mergeCount(prefix, 0, n + 1, lower, upper);
    }

private:
    int mergeCount(vector<long long>& prefix, int left, int right, int lower, int upper) {
        if (right - left <= 1) return 0;

        int mid = left + (right - left) / 2;
        int count = mergeCount(prefix, left, mid, lower, upper)
                  + mergeCount(prefix, mid, right, lower, upper);

        int j = mid, k = mid;
        for (int i = left; i < mid; i++) {
            while (k < right && prefix[k] - prefix[i] < lower) k++;
            while (j < right && prefix[j] - prefix[i] <= upper) j++;
            count += j - k;
        }

        inplace_merge(prefix.begin() + left, prefix.begin() + mid, prefix.begin() + right);
        return count;
    }
};