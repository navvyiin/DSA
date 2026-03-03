import java.util.*;

class Solution {
    public boolean isRectangleCover(int[][] rectangles) {
        long areaSum = 0;
        
        int minX = Integer.MAX_VALUE;
        int minY = Integer.MAX_VALUE;
        int maxX = Integer.MIN_VALUE;
        int maxY = Integer.MIN_VALUE;
        
        Set<String> corners = new HashSet<>();
        
        for (int[] r : rectangles) {
            int x1 = r[0], y1 = r[1], x2 = r[2], y2 = r[3];
            
            // Update bounding rectangle
            minX = Math.min(minX, x1);
            minY = Math.min(minY, y1);
            maxX = Math.max(maxX, x2);
            maxY = Math.max(maxY, y2);
            
            // Sum area
            areaSum += (long)(x2 - x1) * (y2 - y1);
            
            // Four corners of current rectangle
            String[] rectCorners = {
                x1 + "," + y1,
                x1 + "," + y2,
                x2 + "," + y1,
                x2 + "," + y2
            };
            
            for (String corner : rectCorners) {
                if (!corners.add(corner)) {
                    corners.remove(corner);
                }
            }
        }
        
        // Check bounding rectangle area
        long boundingArea = (long)(maxX - minX) * (maxY - minY);
        if (areaSum != boundingArea) {
            return false;
        }
        
        // The set must contain exactly 4 corners
        if (corners.size() != 4) {
            return false;
        }
        
        // They must be the corners of the bounding rectangle
        String[] expected = {
            minX + "," + minY,
            minX + "," + maxY,
            maxX + "," + minY,
            maxX + "," + maxY
        };
        
        for (String corner : expected) {
            if (!corners.contains(corner)) {
                return false;
            }
        }
        
        return true;
    }
}