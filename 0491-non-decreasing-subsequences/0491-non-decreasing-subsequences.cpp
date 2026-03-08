#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> path;
        backtrack(nums, 0, path, result);
        return result;
    }

private:
    void backtrack(vector<int>& nums, int start, vector<int>& path, vector<vector<int>>& result) {
        if (path.size() >= 2)
            result.push_back(path);

        set<int> used;

        for (int i = start; i < nums.size(); i++) {
            if ((!path.empty() && nums[i] < path.back()) || used.count(nums[i]))
                continue;

            used.insert(nums[i]);
            path.push_back(nums[i]);

            backtrack(nums, i + 1, path, result);

            path.pop_back();
        }
    }
};