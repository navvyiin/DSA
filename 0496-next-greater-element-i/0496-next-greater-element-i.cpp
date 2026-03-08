#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> next;
        stack<int> st;

        for (int num : nums2) {
            while (!st.empty() && st.top() < num) {
                next[st.top()] = num;
                st.pop();
            }
            st.push(num);
        }

        while (!st.empty()) {
            next[st.top()] = -1;
            st.pop();
        }

        vector<int> result;
        for (int num : nums1) {
            result.push_back(next[num]);
        }

        return result;
    }
};