import java.util.*;

class Solution {
    public List<String> removeInvalidParentheses(String s) {
        List<String> result = new ArrayList<>();
        if (s == null) return result;

        Set<String> visited = new HashSet<>();
        Queue<String> queue = new LinkedList<>();

        queue.offer(s);
        visited.add(s);
        boolean found = false;

        while (!queue.isEmpty()) {
            String curr = queue.poll();

            if (isValid(curr)) {
                result.add(curr);
                found = true;
            }

            // Once valid strings at this level are found,
            // do not generate deeper states
            if (found) continue;

            for (int i = 0; i < curr.length(); i++) {
                char c = curr.charAt(i);
                if (c != '(' && c != ')') continue;

                String next = curr.substring(0, i) + curr.substring(i + 1);
                if (!visited.contains(next)) {
                    visited.add(next);
                    queue.offer(next);
                }
            }
        }

        return result;
    }

    private boolean isValid(String s) {
        int balance = 0;
        for (char c : s.toCharArray()) {
            if (c == '(') {
                balance++;
            } else if (c == ')') {
                if (balance == 0) return false;
                balance--;
            }
        }
        return balance == 0;
    }
}