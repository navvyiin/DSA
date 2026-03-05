var characterReplacement = function(s, k) {
    let count = new Array(26).fill(0);
    let left = 0;
    let maxCount = 0;
    let maxLen = 0;

    for (let right = 0; right < s.length; right++) {
        let idx = s.charCodeAt(right) - 65;
        count[idx]++;
        maxCount = Math.max(maxCount, count[idx]);

        while ((right - left + 1) - maxCount > k) {
            count[s.charCodeAt(left) - 65]--;
            left++;
        }

        maxLen = Math.max(maxLen, right - left + 1);
    }

    return maxLen;
};