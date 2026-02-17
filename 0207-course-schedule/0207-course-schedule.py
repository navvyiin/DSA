from collections import deque

class Solution:
    def canFinish(self, numCourses: int, prerequisites: list[list[int]]) -> bool:
        graph = [[] for _ in range(numCourses)]
        inDegree = [0] * numCourses

        # Build graph and indegree array
        for course, prereq in prerequisites:
            graph[prereq].append(course)
            inDegree[course] += 1

        # Queue of courses with no prerequisites
        queue = deque()
        for i in range(numCourses):
            if inDegree[i] == 0:
                queue.append(i)

        completed = 0

        while queue:
            curr = queue.popleft()
            completed += 1

            for next_course in graph[curr]:
                inDegree[next_course] -= 1
                if inDegree[next_course] == 0:
                    queue.append(next_course)

        return completed == numCourses