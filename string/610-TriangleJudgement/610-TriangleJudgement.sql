-- Last updated: 19/08/2026, 15:59:29
-- -- -- # Write your MySQL query statement below
-- -- -- Select x,y,z,
-- -- -- (
-- -- --     case
-- -- --     when x + y > z and x+z > y and y+z>x then 'Yes'
-- -- --     else 'No'
-- -- --     end
-- -- -- )as triangle
-- -- -- from Triangle;

-- -- # Write your MySQL query statement below
-- -- SELECT 
-- --     *, 
-- --     IF(x + y > z AND y + z > x AND  x + z > y, "Yes", "No") AS triangle 
-- -- FROM 
-- --     Triangle;

-- SELECT x,
--        y,
--        z,
--        CASE
--            WHEN valid = 1 THEN 'Yes'
--            ELSE 'No'
--        END AS triangle
-- FROM (
--     SELECT *,
--            (x + y > z
--             AND x + z > y
--             AND y + z > x) AS valid
--     FROM Triangle
-- ) t;

SELECT t1.x,
       t1.y,
       t1.z,
       CASE
           WHEN t1.x + t1.y > t1.z
            AND t1.x + t1.z > t1.y
            AND t1.y + t1.z > t1.x
           THEN 'Yes'
           ELSE 'No'
       END AS triangle
FROM Triangle t1
JOIN Triangle t2
ON t1.x = t2.x
AND t1.y = t2.y
AND t1.z = t2.z;