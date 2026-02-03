#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> result;
    vector<int> current;

    void backtrack(int start, int n, int k) {
        if (current.size() == k) {
            result.push_back(current);
            return;
        }

        // Prune: remaining numbers must be enough
        for (int i = start; i <= n - (k - current.size()) + 1; i++) {
            current.push_back(i);
            backtrack(i + 1, n, k);
            current.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        backtrack(1, n, k);
        return result;
    }
};