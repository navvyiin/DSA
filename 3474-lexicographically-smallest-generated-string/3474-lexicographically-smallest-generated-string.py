class Solution:
    def generateString(self, str1: str, str2: str) -> str:
        n, m = len(str1), len(str2)
        L = n + m - 1
        
        word = ['?'] * L
        fixed = [False] * L  # positions forced by 'T'
        
        # Step 1: Apply 'T' constraints
        for i in range(n):
            if str1[i] == 'T':
                for j in range(m):
                    idx = i + j
                    if word[idx] == '?' or word[idx] == str2[j]:
                        word[idx] = str2[j]
                        fixed[idx] = True
                    else:
                        return ""
        
        # Step 2: Fill remaining with 'a'
        for i in range(L):
            if word[i] == '?':
                word[i] = 'a'
        
        # Step 3: Handle 'F' constraints safely
        for i in range(n):
            if str1[i] == 'F':
                if ''.join(word[i:i + m]) == str2:
                    changed = False
                    
                    # Try modifying non-fixed positions only
                    for j in range(m - 1, -1, -1):
                        idx = i + j
                        if fixed[idx]:
                            continue
                        
                        original = word[idx]
                        for c in 'abcdefghijklmnopqrstuvwxyz':
                            if c != original:
                                word[idx] = c
                                if ''.join(word[i:i + m]) != str2:
                                    changed = True
                                    break
                                word[idx] = original
                        if changed:
                            break
                    
                    if not changed:
                        return ""
        
        return ''.join(word)