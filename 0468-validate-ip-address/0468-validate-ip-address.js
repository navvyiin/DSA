var validIPAddress = function(queryIP) {
    if (queryIP.includes('.')) {
        const parts = queryIP.split('.');
        if (parts.length !== 4) return "Neither";

        for (let p of parts) {
            if (p.length === 0 || (p.length > 1 && p[0] === '0')) return "Neither";
            if (!/^\d+$/.test(p)) return "Neither";

            const num = Number(p);
            if (num < 0 || num > 255) return "Neither";
        }
        return "IPv4";
    }

    if (queryIP.includes(':')) {
        const parts = queryIP.split(':');
        if (parts.length !== 8) return "Neither";

        for (let p of parts) {
            if (p.length === 0 || p.length > 4) return "Neither";
            if (!/^[0-9a-fA-F]+$/.test(p)) return "Neither";
        }
        return "IPv6";
    }

    return "Neither";
};