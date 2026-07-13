class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        string digits = "123456789";

        for (int len = 2; len <= 9; len++) {
            for (int i = 0; i + len <= 9; i++) {
                int num = stoi(digits.substr(i, len));
                if (num >= low && num <= high)
                    ans.push_back(num);
            }
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};