class Solution {
public:
    int lastRemaining(int n) {
        long head = 1;        // first remaining number
        long step = 1;        // gap between remaining numbers
        int remaining = n;    
        bool left = true;     // direction flag
        
        while (remaining > 1) {
            // If we eliminate from left,
            // or from right with odd count,
            // head moves forward.
            if (left || (remaining % 2 == 1)) {
                head += step;
            }
            
            remaining /= 2;   // half numbers remain
            step *= 2;        // gap doubles
            left = !left;     // change direction
        }
        
        return head;
    }
};