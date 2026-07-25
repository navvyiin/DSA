class Solution {
public:
    int maxProduct(int n) {
        vector<int> d;
        while (n > 0) {
            d.push_back(n % 10);
            n /= 10;
        }

        int ans = 0;
        for (int i = 0; i < d.size(); i++) {
            for (int j = i + 1; j < d.size(); j++) {
                ans = max(ans, d[i] * d[j]);
            }
        }

        return ans;
    }
};