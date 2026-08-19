-- Last updated: 19/08/2026, 15:50:52
-- -- # Write your MySQL query statement below
-- -- Select person_name
-- -- from (
-- --     SELECT person_name,
-- --     turn,
-- --     SUM(Weight) over(Order by turn)as total_weight
-- --     FROM Queue
-- -- )t
-- -- where total_weight <= 1000
-- -- Order by turn desc
-- -- limit 1;

-- # Write your MySQL query statement below
-- with cte as (select person_name, turn,
-- sum(weight) over (order by turn ) as running_weight
-- from queue)

-- select c.person_name
-- from cte c
-- where running_weight<=1000
-- order by c.turn desc
-- limit 1

# Write your MySQL query statement below
SELECT person_name
FROM (
    SELECT *, SUM(WEIGHT) OVER (ORDER BY TURN) AS CUM_WEIGHT
    FROM queue
) A
WHERE CUM_WEIGHT <= 1000
ORDER BY TURN DESC
LIMIT 1

