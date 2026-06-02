class Solution:
    def earliestFinishTime(self, landStartTime, landDuration,
                           waterStartTime, waterDuration):
        ans = float('inf')

        for i in range(len(landStartTime)):
            land_finish = landStartTime[i] + landDuration[i]

            for j in range(len(waterStartTime)):
                water_finish = waterStartTime[j] + waterDuration[j]

                # Land -> Water
                finish1 = max(waterStartTime[j], land_finish) + waterDuration[j]

                # Water -> Land
                finish2 = max(landStartTime[i], water_finish) + landDuration[i]

                ans = min(ans, finish1, finish2)

        return ans