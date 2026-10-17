class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> arr;
        for (int i = 0; i < n; i++) {
            int x = nums[i], sum = 0;
            while (x > 0) {
                sum += x % 10;
                x /= 10;
            }
            arr.push_back({sum, nums[i]});
        }
        sort(arr.begin(), arr.end());
        unordered_map<int, int> target;
        for (int i = 0; i < n; i++) {
            target[arr[i].second] = i;
        }
        vector<bool> visited(n, false);
        int swaps = 0;
        for (int i = 0; i < n; i++) {
            if (visited[i] || target[nums[i]] == i)
                continue;
            int cycle = 0, j = i;
            while (!visited[j]) {
                visited[j] = true;
                j = target[nums[j]];
                cycle++;
            }
            swaps += cycle - 1;
        }
        return swaps;
    }
};