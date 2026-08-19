-- Last updated: 19/08/2026, 15:59:19
-- SELECT MAX(num) AS num
-- FROM (
--     SELECT num
--     FROM MyNumbers
--     GROUP BY num
--     HAVING COUNT(*) = 1
-- ) AS t;

# Write your MySQL query statement below

SELECT MAX(num) as num
FROM mynumbers n
where num IN (
    SELECT num
    FROM mynumbers
    GROUP BY num
    HAVING COUNT(*)=1
)