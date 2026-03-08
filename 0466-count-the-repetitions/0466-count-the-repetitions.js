var getMaxRepetitions = function(s1, n1, s2, n2) {
    if (n1 === 0) return 0;

    let index = 0;
    let count = 0;
    const recall = new Map();

    const s1Count = new Array(n1 + 1).fill(0);
    const s2Count = new Array(n1 + 1).fill(0);

    for (let i = 1; i <= n1; i++) {
        for (let c of s1) {
            if (c === s2[index]) {
                index++;
                if (index === s2.length) {
                    index = 0;
                    count++;
                }
            }
        }

        s1Count[i] = i;
        s2Count[i] = count;

        if (recall.has(index)) {
            const prev = recall.get(index);
            const preLoopS1 = prev[0];
            const preLoopS2 = prev[1];

            const inLoopS1 = i - prev[0];
            const inLoopS2 = count - prev[1];

            let result = preLoopS2;

            const remaining = n1 - preLoopS1;
            const loops = Math.floor(remaining / inLoopS1);

            result += loops * inLoopS2;

            const rest = remaining % inLoopS1;
            result += s2Count[preLoopS1 + rest] - s2Count[preLoopS1];

            return Math.floor(result / n2);
        } else {
            recall.set(index, [i, count]);
        }
    }

    return Math.floor(s2Count[n1] / n2);
};