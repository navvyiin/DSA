/**
 * @param {string} s
 * @param {string} t
 * @return {string}
 */
var minWindow = function(s, t) {
    if (t.length > s.length) return "";

    const need = new Map();
    for (const ch of t) {
        need.set(ch, (need.get(ch) || 0) + 1);
    }

    let required = t.length;
    let left = 0;
    let minLen = Infinity;
    let start = 0;

    for (let right = 0; right < s.length; right++) {
        const ch = s[right];

        if (need.has(ch)) {
            if (need.get(ch) > 0) {
                required--;
            }
            need.set(ch, need.get(ch) - 1);
        }

        while (required === 0) {
            if (right - left + 1 < minLen) {
                minLen = right - left + 1;
                start = left;
            }

            const leftChar = s[left];
            if (need.has(leftChar)) {
                need.set(leftChar, need.get(leftChar) + 1);
                if (need.get(leftChar) > 0) {
                    required++;
                }
            }
            left++;
        }
    }

    return minLen === Infinity ? "" : s.substring(start, start + minLen);
};