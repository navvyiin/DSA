class Solution:
    def fractionToDecimal(self, numerator: int, denominator: int) -> str:
        if numerator == 0:
            return "0"

        result = []

        # Handle sign
        if (numerator < 0) ^ (denominator < 0):
            result.append("-")

        # Work with positive values
        num = abs(numerator)
        den = abs(denominator)

        # Integer part
        integer_part = num // den
        result.append(str(integer_part))

        remainder = num % den
        if remainder == 0:
            return "".join(result)

        result.append(".")

        # Map remainder to index in result
        remainder_map = {}

        while remainder != 0:
            if remainder in remainder_map:
                index = remainder_map[remainder]
                result.insert(index, "(")
                result.append(")")
                break

            remainder_map[remainder] = len(result)

            remainder *= 10
            digit = remainder // den
            result.append(str(digit))
            remainder %= den

        return "".join(result)