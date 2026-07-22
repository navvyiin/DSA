from typing import List

class SparseTableMax:
    def __init__(self, arr):
        n = len(arr)
        self.n = n
        self.log = [0] * (n + 1)
        for i in range(2, n + 1):
            self.log[i] = self.log[i // 2] + 1
        self.table = [arr[:]]
        j = 1
        while (1 << j) <= n:
            prev = self.table[-1]
            half = 1 << (j - 1)
            cur = [max(prev[i], prev[i + half]) for i in range(n - (1 << j) + 1)]
            self.table.append(cur)
            j += 1

    def query(self, l, r):  # inclusive
        if l > r:
            return float('-inf')
        k = self.log[r - l + 1]
        return max(self.table[k][l], self.table[k][r - (1 << k) + 1])


class SparseTableMin:
    def __init__(self, arr):
        n = len(arr)
        self.n = n
        self.log = [0] * (n + 1)
        for i in range(2, n + 1):
            self.log[i] = self.log[i // 2] + 1
        self.table = [arr[:]]
        j = 1
        while (1 << j) <= n:
            prev = self.table[-1]
            half = 1 << (j - 1)
            cur = [min(prev[i], prev[i + half]) for i in range(n - (1 << j) + 1)]
            self.table.append(cur)
            j += 1

    def query(self, l, r):
        if l > r:
            return float('inf')
        k = self.log[r - l + 1]
        return min(self.table[k][l], self.table[k][r - (1 << k) + 1])


class Solution:
    def maxActiveSectionsAfterTrade(self, s: str, queries: List[List[int]]) -> List[int]:
        n = len(s)
        blockType, blockStart, blockEnd = [], [], []
        i = 0
        while i < n:
            j = i
            while j < n and s[j] == s[i]:
                j += 1
            blockType.append(s[i])
            blockStart.append(i)
            blockEnd.append(j - 1)
            i = j

        B = len(blockType)
        blockLen = [blockEnd[k] - blockStart[k] + 1 for k in range(B)]
        totalOnes = s.count('1')

        NEG = -1
        POS_INF = float('inf')

        oneLen = [blockLen[k] if blockType[k] == '1' else POS_INF for k in range(B)]
        zeroLen = [blockLen[k] if blockType[k] == '0' else NEG for k in range(B)]
        pairSum = [NEG] * B
        for k in range(1, B - 1):
            if blockType[k] == '1':
                pairSum[k] = blockLen[k - 1] + blockLen[k + 1]

        stMinOne = SparseTableMin(oneLen)
        stMaxZero = SparseTableMax(zeroLen)
        stMaxPair = SparseTableMax(pairSum)

        def blockIndexOf(pos):
            lo, hi = 0, B - 1
            while lo < hi:
                mid = (lo + hi + 1) // 2
                if blockStart[mid] <= pos:
                    lo = mid
                else:
                    hi = mid - 1
            return lo

        ans = []
        for l, r in queries:
            bi = blockIndexOf(l)
            bj = blockIndexOf(r)
            bestGain = 0

            if bj - bi >= 2:
                omin = stMinOne.query(bi + 1, bj - 1)
                if omin != POS_INF:
                    clippedBi = blockEnd[bi] - l + 1
                    clippedBj = r - blockStart[bj] + 1

                    zvals = [stMaxZero.query(bi + 1, bj - 1)]
                    if blockType[bi] == '0':
                        zvals.append(clippedBi)
                    if blockType[bj] == '0':
                        zvals.append(clippedBj)
                    zmax = max(zvals)

                    optionA = NEG
                    optionA = max(optionA, stMaxPair.query(bi + 2, bj - 2))

                    i1 = bi + 1
                    if blockType[i1] == '1':
                        leftLen = clippedBi
                        rightLen = clippedBj if i1 + 1 == bj else blockLen[i1 + 1]
                        optionA = max(optionA, leftLen + rightLen)

                    i2 = bj - 1
                    if i2 != i1 and blockType[i2] == '1':
                        rightLen = clippedBj
                        leftLen = clippedBi if i2 - 1 == bi else blockLen[i2 - 1]
                        optionA = max(optionA, leftLen + rightLen)

                    bestGain = max(optionA, zmax - omin)

            ans.append(totalOnes + max(0, bestGain))

        return ans