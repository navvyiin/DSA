import java.util.*;
class Solution {
    private String expression;
    private int index;
    public List<String> braceExpansionII(String expression) {
        this.expression = expression;
        this.index = 0;
        Set<String> result = parseExpression();
        List<String> ans = new ArrayList<>(result);
        Collections.sort(ans);
        return ans;
    }
    private Set<String> parseExpression() {
        Set<String> result = new HashSet<>();
        while (true) {
            result.addAll(parseTerm());
            if (index < expression.length() && expression.charAt(index) == ',') {
                index++;
            } else {
                break;
            }
        }
        return result;
    }
    private Set<String> parseTerm() {
        Set<String> result = new HashSet<>();
        result.add("");
        while (index < expression.length()) {
            char ch = expression.charAt(index);
            if (ch == ',' || ch == '}') {
                break;
            }
            Set<String> part;
            if (ch == '{') {
                index++;
                part = parseExpression();
                index++;
            } else {
                part = new HashSet<>();
                part.add(String.valueOf(ch));
                index++;
            }
            result = concatenate(result, part);
        }
        return result;
    }
    private Set<String> concatenate(Set<String> a, Set<String> b) {
        Set<String> result = new HashSet<>();
        for (String x : a) {
            for (String y : b) {
                result.add(x + y);
            }
        }
        return result;
    }
}