class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefixGcd;
        prefixGcd.reserve(n);

        int mx = 0;
        for (int x : nums) {
            mx = max(mx, x);
            prefixGcd.push_back(gcd(x, mx));
        }

        sort(prefixGcd.begin(), prefixGcd.end());

        long long ans = 0;
        int l = 0, r = n - 1;

        while (l < r) {
            ans += gcd(prefixGcd[l], prefixGcd[r]);
            l++;
            r--;
        }

        return ans;
    }
};