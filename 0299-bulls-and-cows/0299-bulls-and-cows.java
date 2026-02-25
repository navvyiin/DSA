class Solution {
    public String getHint(String secret, String guess) {
        int bulls = 0;
        int[] count = new int[10];

        for (int i = 0; i < secret.length(); i++) {
            char s = secret.charAt(i);
            char g = guess.charAt(i);

            if (s == g) {
                bulls++;
            } else {
                count[s - '0']++;
                count[g - '0']--;
            }
        }

        int cows = 0;
        for (int i = 0; i < 10; i++) {
            if (count[i] > 0) {
                cows += count[i];
            }
        }

        cows = secret.length() - bulls - cows;
        return bulls + "A" + cows + "B";
    }
}