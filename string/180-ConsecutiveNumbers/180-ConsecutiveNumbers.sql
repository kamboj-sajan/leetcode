-- Last updated: 19/08/2026, 16:05:58
-- -- # Write your MySQL query statement below
-- -- Select distinct l1.num as ConsecutiveNums
-- -- from Logs l1
-- -- JOin Logs l2
-- -- on l1.id + 1 = l2.id
-- -- JOIN Logs l3
-- -- on l2.id + 1 = l3.id
-- -- WHERE l1.num = l2.num
-- -- and l2.num = l3.num

-- SELECT DISTINCT num AS ConsecutiveNums
-- FROM (
--     SELECT num,
--            LAG(num, 1) OVER (ORDER BY id) AS prev1,
--            LAG(num, 2) OVER (ORDER BY id) AS prev2
--     FROM Logs
-- ) t
-- WHERE num = prev1
-- AND num = prev2;

# Write your MySQL query statement below
WITH ConsecutiveRows AS (
    SELECT 
        num,
        LEAD(num, 1) OVER (ORDER BY id) AS next_num,
        LEAD(num, 2) OVER (ORDER BY id) AS next_next_num
    FROM Logs
)
SELECT DISTINCT num AS ConsecutiveNums
FROM ConsecutiveRows
WHERE num = next_num AND num = next_next_num;