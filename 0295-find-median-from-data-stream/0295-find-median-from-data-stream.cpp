#include <queue>
#include <vector>
using namespace std;

class MedianFinder {
private:
    // Max heap for the lower half
    priority_queue<int> left;
    // Min heap for the upper half
    priority_queue<int, vector<int>, greater<int>> right;

public:
    MedianFinder() {}

    void addNum(int num) {
        // Step 1: add to max heap
        left.push(num);

        // Step 2: balance order (largest of left goes to right)
        right.push(left.top());
        left.pop();

        // Step 3: balance sizes
        if (right.size() > left.size()) {
            left.push(right.top());
            right.pop();
        }
    }

    double findMedian() {
        if (left.size() > right.size()) {
            return left.top();
        }
        return (left.top() + right.top()) / 2.0;
    }
};