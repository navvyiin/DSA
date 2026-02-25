var maxProduct = function(words) {
    const n = words.length;
    const masks = new Array(n);
    const lengths = new Array(n);

    // Build bitmasks
    for (let i = 0; i < n; i++) {
        let mask = 0;
        for (const ch of words[i]) {
            mask |= 1 << (ch.charCodeAt(0) - 97);
        }
        masks[i] = mask;
        lengths[i] = words[i].length;
    }

    let max = 0;

    // Compare all pairs
    for (let i = 0; i < n; i++) {
        for (let j = i + 1; j < n; j++) {
            if ((masks[i] & masks[j]) === 0) {
                max = Math.max(max, lengths[i] * lengths[j]);
            }
        }
    }

    return max;
};