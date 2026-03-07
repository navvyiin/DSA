class Solution {
    public int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int rounds = minutesToTest / minutesToDie;
        int states = rounds + 1;
        
        int pigs = 0;
        int capacity = 1;
        
        while (capacity < buckets) {
            pigs++;
            capacity *= states;
        }
        
        return pigs;
    }
}