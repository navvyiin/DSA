class Solution {
    public int longestPalindrome(String s) {
        int[] count = new int[128];
        
        for (char c : s.toCharArray()) {
            count[c]++;
        }
        
        int length = 0;
        boolean oddFound = false;
        
        for (int c : count) {
            length += (c / 2) * 2;
            if (c % 2 == 1) oddFound = true;
        }
        
        if (oddFound) length++;
        
        return length;
    }
}