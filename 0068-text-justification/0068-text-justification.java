import java.util.*;

class Solution {
    public List<String> fullJustify(String[] words, int maxWidth) {
        List<String> result = new ArrayList<>();
        int i = 0;

        while (i < words.length) {
            int lineLen = words[i].length();
            int j = i + 1;

            // Greedily fit as many words as possible
            while (j < words.length && lineLen + 1 + words[j].length() <= maxWidth) {
                lineLen += 1 + words[j].length();
                j++;
            }

            int wordCount = j - i;
            StringBuilder line = new StringBuilder();

            // Last line or single word → left-justified
            if (j == words.length || wordCount == 1) {
                for (int k = i; k < j; k++) {
                    line.append(words[k]);
                    if (k < j - 1) line.append(" ");
                }
                while (line.length() < maxWidth) {
                    line.append(" ");
                }
            } 
            // Fully justified
            else {
                int totalWordLen = 0;
                for (int k = i; k < j; k++) {
                    totalWordLen += words[k].length();
                }

                int totalSpaces = maxWidth - totalWordLen;
                int gaps = wordCount - 1;
                int spaceEach = totalSpaces / gaps;
                int extraSpaces = totalSpaces % gaps;

                for (int k = i; k < j; k++) {
                    line.append(words[k]);
                    if (k < j - 1) {
                        int spaces = spaceEach + (extraSpaces > 0 ? 1 : 0);
                        for (int s = 0; s < spaces; s++) {
                            line.append(" ");
                        }
                        if (extraSpaces > 0) extraSpaces--;
                    }
                }
            }

            result.add(line.toString());
            i = j;
        }

        return result;
    }
}