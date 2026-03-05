var originalDigits = function(s) {
    let count = new Array(26).fill(0);
    
    for (let c of s) {
        count[c.charCodeAt(0) - 97]++;
    }

    let out = new Array(10).fill(0);

    out[0] = count['z'.charCodeAt(0) - 97];
    out[2] = count['w'.charCodeAt(0) - 97];
    out[4] = count['u'.charCodeAt(0) - 97];
    out[6] = count['x'.charCodeAt(0) - 97];
    out[8] = count['g'.charCodeAt(0) - 97];

    out[3] = count['h'.charCodeAt(0) - 97] - out[8];
    out[5] = count['f'.charCodeAt(0) - 97] - out[4];
    out[7] = count['s'.charCodeAt(0) - 97] - out[6];

    out[1] = count['o'.charCodeAt(0) - 97] - out[0] - out[2] - out[4];
    out[9] = count['i'.charCodeAt(0) - 97] - out[5] - out[6] - out[8];

    let result = "";

    for (let i = 0; i <= 9; i++) {
        result += i.toString().repeat(out[i]);
    }

    return result;
};