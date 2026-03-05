var strongPasswordChecker = function(password) {
    let n = password.length;
    
    let hasLower = 0, hasUpper = 0, hasDigit = 0;
    for (let c of password) {
        if (c >= 'a' && c <= 'z') hasLower = 1;
        else if (c >= 'A' && c <= 'Z') hasUpper = 1;
        else if (c >= '0' && c <= '9') hasDigit = 1;
    }
    
    let missing = 3 - (hasLower + hasUpper + hasDigit);
    
    let replace = 0;
    let one = 0, two = 0;
    
    for (let i = 0; i < n; ) {
        let j = i;
        while (i < n && password[i] === password[j]) i++;
        let len = i - j;
        
        if (len >= 3) {
            replace += Math.floor(len / 3);
            if (len % 3 === 0) one++;
            else if (len % 3 === 1) two++;
        }
    }
    
    if (n < 6) {
        return Math.max(missing, 6 - n);
    }
    
    if (n <= 20) {
        return Math.max(missing, replace);
    }
    
    let deleteCount = n - 20;
    let del = deleteCount;
    
    let use = Math.min(one, del);
    replace -= use;
    del -= use;
    
    use = Math.min(Math.floor(del / 2), two);
    replace -= use;
    del -= use * 2;
    
    use = Math.floor(del / 3);
    replace -= use;
    
    return deleteCount + Math.max(missing, replace);
};