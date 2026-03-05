class Solution:
    def readBinaryWatch(self, turnedOn: int):
        result = []
        
        for hour in range(12):
            for minute in range(60):
                if (bin(hour).count('1') + bin(minute).count('1')) == turnedOn:
                    result.append(f"{hour}:{minute:02d}")
        
        return result