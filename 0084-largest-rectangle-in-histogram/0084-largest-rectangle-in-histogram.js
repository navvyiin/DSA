/**
 * @param {number[]} heights
 * @return {number}
 */
var largestRectangleArea = function(heights) {
    const stack = [];
    let maxArea = 0;

    // Add a sentinel bar of height 0
    heights.push(0);

    for (let i = 0; i < heights.length; i++) {
        while (stack.length > 0 && heights[i] < heights[stack[stack.length - 1]]) {
            const h = heights[stack.pop()];
            const width = stack.length === 0
                ? i
                : i - stack[stack.length - 1] - 1;

            maxArea = Math.max(maxArea, h * width);
        }
        stack.push(i);
    }

    return maxArea;
};