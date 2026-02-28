import java.util.*;

class Twitter {

    private static class Tweet {
        int time;
        int id;
        Tweet(int time, int id) {
            this.time = time;
            this.id = id;
        }
    }

    private int timestamp;
    private Map<Integer, List<Tweet>> tweets;
    private Map<Integer, Set<Integer>> follows;

    public Twitter() {
        timestamp = 0;
        tweets = new HashMap<>();
        follows = new HashMap<>();
    }

    public void postTweet(int userId, int tweetId) {
        tweets.computeIfAbsent(userId, k -> new ArrayList<>())
              .add(new Tweet(timestamp++, tweetId));
    }

    public List<Integer> getNewsFeed(int userId) {
        PriorityQueue<Tweet> pq = new PriorityQueue<>(
            (a, b) -> b.time - a.time
        );

        // Add user's own tweets
        if (tweets.containsKey(userId)) {
            for (Tweet t : tweets.get(userId)) {
                pq.offer(t);
            }
        }

        // Add followed users' tweets
        if (follows.containsKey(userId)) {
            for (int followee : follows.get(userId)) {
                if (tweets.containsKey(followee)) {
                    for (Tweet t : tweets.get(followee)) {
                        pq.offer(t);
                    }
                }
            }
        }

        List<Integer> feed = new ArrayList<>();
        int count = 0;
        while (!pq.isEmpty() && count < 10) {
            feed.add(pq.poll().id);
            count++;
        }
        return feed;
    }

    public void follow(int followerId, int followeeId) {
        follows.computeIfAbsent(followerId, k -> new HashSet<>())
               .add(followeeId);
    }

    public void unfollow(int followerId, int followeeId) {
        if (follows.containsKey(followerId)) {
            follows.get(followerId).remove(followeeId);
        }
    }
}