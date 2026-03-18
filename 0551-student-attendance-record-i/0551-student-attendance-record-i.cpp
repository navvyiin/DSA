class Solution {
public:
    bool checkRecord(string s) {
        int absences = 0;
        int lateStreak = 0;
        
        for (char c : s) {
            if (c == 'A') {
                absences++;
                if (absences >= 2) return false;
                lateStreak = 0;
            } 
            else if (c == 'L') {
                lateStreak++;
                if (lateStreak >= 3) return false;
            } 
            else { // 'P'
                lateStreak = 0;
            }
        }
        
        return true;
    }
};