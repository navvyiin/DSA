import java.util.*;

class Solution {
    public int leastBricks(List<List<Integer>> wall) {
        Map<Integer, Integer> edgeCount = new HashMap<>();
        
        for (List<Integer> row : wall) {
            int sum = 0;
            
            // Skip the last brick to avoid the right boundary
            for (int i = 0; i < row.size() - 1; i++) {
                sum += row.get(i);
                edgeCount.put(sum, edgeCount.getOrDefault(sum, 0) + 1);
            }
        }
        
        int maxEdges = 0;
        for (int count : edgeCount.values()) {
            maxEdges = Math.max(maxEdges, count);
        }
        
        return wall.size() - maxEdges;
    }
}