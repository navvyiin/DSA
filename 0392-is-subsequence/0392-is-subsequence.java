import java.util.*;

class Solution {

    // Basic two-pointer solution
    public boolean isSubsequence(String s, String t) {
        int i = 0, j = 0;
        
        while (i < s.length() && j < t.length()) {
            if (s.charAt(i) == t.charAt(j)) {
                i++;
            }
            j++;
        }
        
        return i == s.length();
    }
}


/*
Follow-up solution (for many incoming s queries):

Preprocess string t once. Build an index list for each character.
Then for each s, use binary search to find the next valid position.

Time:
Preprocessing: O(|t|)
Each query: O(|s| log |t|)
*/

class FollowUpSolution {

    private Map<Character, List<Integer>> map;

    public FollowUpSolution(String t) {
        map = new HashMap<>();
        
        for (int i = 0; i < t.length(); i++) {
            char c = t.charAt(i);
            map.computeIfAbsent(c, k -> new ArrayList<>()).add(i);
        }
    }

    public boolean isSubsequence(String s) {
        int prevIndex = -1;

        for (char c : s.toCharArray()) {
            if (!map.containsKey(c)) {
                return false;
            }

            List<Integer> indices = map.get(c);
            int pos = Collections.binarySearch(indices, prevIndex + 1);

            if (pos < 0) {
                pos = -pos - 1;
            }

            if (pos == indices.size()) {
                return false;
            }

            prevIndex = indices.get(pos);
        }

        return true;
    }
}