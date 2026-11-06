var countServers = function(n, logs, x, queries) {
    logs.sort((a, b) => a[1] - b[1]);
    const sortedQueries = queries.map((q, i) => [q, i]);
    sortedQueries.sort((a, b) => a[0] - b[0]);
    const count = new Int32Array(n + 1);
    const result = new Array(queries.length);
    let left = 0;
    let right = 0;
    let activeServers = 0;
    for (const [q, index] of sortedQueries) {
        const start = q - x;
        while (right < logs.length && logs[right][1] <= q) {
            const server = logs[right][0];
            if (count[server] === 0) {
                activeServers++;
            }
            count[server]++;
            right++;
        }
        while (left < right && logs[left][1] < start) {
            const server = logs[left][0];
            count[server]--;
            if (count[server] === 0) {
                activeServers--;
            }
            left++;
        }
        result[index] = n - activeServers;
    }
    return result;
};