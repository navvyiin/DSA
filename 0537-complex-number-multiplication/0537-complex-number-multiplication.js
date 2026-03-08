var complexNumberMultiply = function(num1, num2) {
    const parse = (s) => {
        const parts = s.split('+');
        const real = parseInt(parts[0]);
        const imag = parseInt(parts[1].slice(0, -1));
        return [real, imag];
    };

    const [a, b] = parse(num1);
    const [c, d] = parse(num2);

    const real = a * c - b * d;
    const imag = a * d + b * c;

    return real + "+" + imag + "i";
};