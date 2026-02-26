var findItinerary = function(tickets) {
    const graph = new Map();

    for (const [from, to] of tickets) {
        if (!graph.has(from)) graph.set(from, []);
        graph.get(from).push(to);
    }

    for (const dests of graph.values()) {
        dests.sort().reverse();
    }

    const route = [];

    const dfs = (airport) => {
        const dests = graph.get(airport);
        while (dests && dests.length > 0) {
            dfs(dests.pop());
        }
        route.push(airport);
    };

    dfs("JFK");
    return route.reverse();
};