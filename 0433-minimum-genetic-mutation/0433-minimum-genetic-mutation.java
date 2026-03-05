import java.util.*;

class Solution {
    public int minMutation(String startGene, String endGene, String[] bank) {
        Set<String> bankSet = new HashSet<>(Arrays.asList(bank));
        if (!bankSet.contains(endGene)) return -1;

        char[] genes = {'A','C','G','T'};
        Queue<String> queue = new LinkedList<>();
        Set<String> visited = new HashSet<>();

        queue.offer(startGene);
        visited.add(startGene);
        int steps = 0;

        while (!queue.isEmpty()) {
            int size = queue.size();

            for (int s = 0; s < size; s++) {
                String current = queue.poll();

                if (current.equals(endGene)) return steps;

                char[] arr = current.toCharArray();

                for (int i = 0; i < arr.length; i++) {
                    char old = arr[i];

                    for (char g : genes) {
                        if (g == old) continue;

                        arr[i] = g;
                        String next = new String(arr);

                        if (bankSet.contains(next) && !visited.contains(next)) {
                            visited.add(next);
                            queue.offer(next);
                        }
                    }

                    arr[i] = old;
                }
            }

            steps++;
        }

        return -1;
    }
}