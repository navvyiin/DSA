SELECT 
    ROUND(
        AVG(
            EXISTS (
                SELECT 1
                FROM Activity a2
                WHERE a2.player_id = a1.player_id
                  AND a2.event_date = DATE_ADD(a1.first_day, INTERVAL 1 DAY)
            )
        ),
        2
    ) AS fraction
FROM (
    SELECT player_id, MIN(event_date) AS first_day
    FROM Activity
    GROUP BY player_id
) a1;