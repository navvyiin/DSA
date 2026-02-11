var partition = function(s) {
    const result = [];
    const path = [];

    function isPalindrome(left, right) {
        while (left < right) {
            if (s[left] !== s[right]) return false;
            left++;
            right--;
        }
        return true;
    }

    function backtrack(start) {
        if (start === s.length) {
            result.push([...path]);
            return;
        }

        for (let end = start; end < s.length; end++) {
            if (isPalindrome(start, end)) {
                path.push(s.substring(start, end + 1));
                backtrack(end + 1);
                path.pop(); // backtrack
            }
        }
    }

    backtrack(0);
    return result;
};