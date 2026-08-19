-- Last updated: 19/08/2026, 15:50:41
SELECT
    query_name,
    ROUND(AVG(rating / position), 2) AS quality,
    ROUND(
        AVG(
            CASE
                WHEN rating < 3 THEN 1
                ELSE 0
            END
        ) * 100,
        2
    ) AS poor_query_percentage
FROM Queries
GROUP BY query_name;