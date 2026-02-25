var removeDuplicateLetters = function(s) {
    const lastIndex = new Map();
    for (let i = 0; i < s.length; i++) {
        lastIndex.set(s[i], i);
    }

    const stack = [];
    const seen = new Set();

    for (let i = 0; i < s.length; i++) {
        const ch = s[i];

        if (seen.has(ch)) continue;

        while (
            stack.length &&
            stack[stack.length - 1] > ch &&
            lastIndex.get(stack[stack.length - 1]) > i
        ) {
            seen.delete(stack.pop());
        }

        stack.push(ch);
        seen.add(ch);
    }

    return stack.join('');
};