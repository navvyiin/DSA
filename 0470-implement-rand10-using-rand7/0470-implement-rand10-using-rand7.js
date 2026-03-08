var rand10 = function() {
    while (true) {
        let num = (rand7() - 1) * 7 + rand7(); // range 1..49
        if (num <= 40) {
            return (num - 1) % 10 + 1;
        }
    }
};