#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        multiset<int> lo, hi;
        vector<double> result;

        auto balance = [&]() {
            while (lo.size() > hi.size() + 1) {
                hi.insert(*lo.rbegin());
                lo.erase(prev(lo.end()));
            }
            while (lo.size() < hi.size()) {
                lo.insert(*hi.begin());
                hi.erase(hi.begin());
            }
        };

        auto add = [&](int num) {
            if (lo.empty() || num <= *lo.rbegin())
                lo.insert(num);
            else
                hi.insert(num);
            balance();
        };

        auto remove = [&](int num) {
            if (lo.find(num) != lo.end())
                lo.erase(lo.find(num));
            else
                hi.erase(hi.find(num));
            balance();
        };

        for (int i = 0; i < nums.size(); i++) {
            add(nums[i]);

            if (i >= k - 1) {
                if (k % 2)
                    result.push_back(*lo.rbegin());
                else
                    result.push_back(((double)*lo.rbegin() + *hi.begin()) / 2.0);

                remove(nums[i - k + 1]);
            }
        }

        return result;
    }
};