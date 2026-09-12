import java.util.*;

class Solution {
    public int[] maximumWeight(List<List<Integer>> intervals) {
        int n = intervals.size();

        // [start, end, weight, originalIndex]
        int[][] arr = new int[n][4];

        for (int i = 0; i < n; i++) {
            arr[i][0] = intervals.get(i).get(0);
            arr[i][1] = intervals.get(i).get(1);
            arr[i][2] = intervals.get(i).get(2);
            arr[i][3] = i;
        }

        // Sort by start time, then by original index.
        Arrays.sort(arr, (a, b) -> {
            if (a[0] != b[0]) {
                return Integer.compare(a[0], b[0]);
            }
            return Integer.compare(a[3], b[3]);
        });

        // Find the first interval with start > current end.
        int[] next = new int[n];

        for (int i = 0; i < n; i++) {
            int lo = i + 1;
            int hi = n;

            while (lo < hi) {
                int mid = lo + (hi - lo) / 2;

                if (arr[mid][0] > arr[i][1]) {
                    hi = mid;
                } else {
                    lo = mid + 1;
                }
            }

            next[i] = lo;
        }

        /*
         * dp[i][j] = best score using at most j intervals
         * from indices i ... n-1.
         */
        long[][] dp = new long[n + 1][5];

        @SuppressWarnings("unchecked")
        List<Integer>[][] best = new ArrayList[n + 1][5];

        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= 4; j++) {
                best[i][j] = new ArrayList<>();
            }
        }

        for (int i = n - 1; i >= 0; i--) {
            for (int j = 1; j <= 4; j++) {

                // Skip current interval.
                dp[i][j] = dp[i + 1][j];
                best[i][j] = new ArrayList<>(best[i + 1][j]);

                // Take current interval.
                long takeScore = arr[i][2] + dp[next[i]][j - 1];

                List<Integer> takeList =
                        new ArrayList<>(best[next[i]][j - 1]);

                takeList.add(arr[i][3]);
                Collections.sort(takeList);

                if (takeScore > dp[i][j] ||
                    (takeScore == dp[i][j] &&
                     lexicographicallySmaller(takeList, best[i][j]))) {

                    dp[i][j] = takeScore;
                    best[i][j] = takeList;
                }
            }
        }

        List<Integer> answer = best[0][4];

        int[] result = new int[answer.size()];

        for (int i = 0; i < answer.size(); i++) {
            result[i] = answer.get(i);
        }

        return result;
    }

    private boolean lexicographicallySmaller(
            List<Integer> a,
            List<Integer> b) {

        int len = Math.min(a.size(), b.size());

        for (int i = 0; i < len; i++) {
            if (!a.get(i).equals(b.get(i))) {
                return a.get(i) < b.get(i);
            }
        }

        return a.size() < b.size();
    }
}