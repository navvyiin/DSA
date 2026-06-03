class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime,
                           vector<int>& landDuration,
                           vector<int>& waterStartTime,
                           vector<int>& waterDuration) {

        long long ans = LLONG_MAX;

        ans = min(ans,
                  solve(landStartTime, landDuration,
                        waterStartTime, waterDuration));

        ans = min(ans,
                  solve(waterStartTime, waterDuration,
                        landStartTime, landDuration));

        return (int)ans;
    }

private:
    long long solve(vector<int>& startA, vector<int>& durA,
                    vector<int>& startB, vector<int>& durB) {

        int m = startB.size();

        vector<pair<int,int>> ridesB;

        for (int i = 0; i < m; i++) {
            ridesB.push_back({startB[i], durB[i]});
        }

        sort(ridesB.begin(), ridesB.end());

        vector<int> starts(m);

        for (int i = 0; i < m; i++) {
            starts[i] = ridesB[i].first;
        }

        /*
            prefixMinDur[i]
            = minimum duration among rides with index <= i
        */
        vector<long long> prefixMinDur(m);

        prefixMinDur[0] = ridesB[0].second;

        for (int i = 1; i < m; i++) {
            prefixMinDur[i] =
                min(prefixMinDur[i - 1],
                    (long long)ridesB[i].second);
        }

        /*
            suffixMinOpenPlusDur[i]
            = minimum(start + duration) for index >= i
        */
        vector<long long> suffixMinOpenPlusDur(m);

        suffixMinOpenPlusDur[m - 1] =
            (long long)ridesB[m - 1].first + ridesB[m - 1].second;

        for (int i = m - 2; i >= 0; i--) {
            suffixMinOpenPlusDur[i] =
                min(suffixMinOpenPlusDur[i + 1],
                    (long long)ridesB[i].first + ridesB[i].second);
        }

        long long best = LLONG_MAX;

        for (int i = 0; i < startA.size(); i++) {

            long long finishA =
                (long long)startA[i] + durA[i];

            /*
                Need:
                min over B of max(finishA, startB) + durB
            */

            int idx = upper_bound(starts.begin(),
                                  starts.end(),
                                  finishA)
                      - starts.begin();

            // Case 1: startB <= finishA
            if (idx > 0) {
                best = min(best,
                           finishA + prefixMinDur[idx - 1]);
            }

            // Case 2: startB > finishA
            if (idx < m) {
                best = min(best,
                           suffixMinOpenPlusDur[idx]);
            }
        }

        return best;
    }
};