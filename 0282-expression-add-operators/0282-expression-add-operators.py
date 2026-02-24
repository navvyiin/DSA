class Solution:
    def addOperators(self, num: str, target: int):
        result = []

        def backtrack(index, path, current_value, last_operand):
            # If we've used all digits
            if index == len(num):
                if current_value == target:
                    result.append(path)
                return

            # Try all possible splits
            for i in range(index, len(num)):
                # Avoid numbers with leading zeros
                if i != index and num[index] == '0':
                    break

                current_str = num[index:i + 1]
                current_num = int(current_str)

                if index == 0:
                    # First number, no operator needed
                    backtrack(
                        i + 1,
                        current_str,
                        current_num,
                        current_num
                    )
                else:
                    # Addition
                    backtrack(
                        i + 1,
                        path + "+" + current_str,
                        current_value + current_num,
                        current_num
                    )

                    # Subtraction
                    backtrack(
                        i + 1,
                        path + "-" + current_str,
                        current_value - current_num,
                        -current_num
                    )

                    # Multiplication (handle precedence)
                    backtrack(
                        i + 1,
                        path + "*" + current_str,
                        current_value - last_operand + last_operand * current_num,
                        last_operand * current_num
                    )

        backtrack(0, "", 0, 0)
        return result