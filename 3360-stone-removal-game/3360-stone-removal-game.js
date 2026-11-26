var canAliceWin = function(n) {
    let stonesToRemove = 10;
    let aliceTurn = true;
    while (n >= stonesToRemove) {
        n -= stonesToRemove;
        stonesToRemove--;
        aliceTurn = !aliceTurn;
    }
    return !aliceTurn;
};