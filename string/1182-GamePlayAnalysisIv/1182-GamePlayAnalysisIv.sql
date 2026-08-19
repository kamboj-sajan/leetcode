-- Last updated: 19/08/2026, 15:52:42
-- -- -- Select Round(
-- -- --     AVG(
-- -- --         case 
-- -- --         when a.event_date is NOT NULL then 1
-- -- --         else 0
-- -- --         end
-- -- --     ),
-- -- -- 2)as fraction 
-- -- -- from (
-- -- --     Select player_id , min(event_date)as first_login
-- -- --     from Activity 
-- -- --     Group BY player_id
-- -- -- )f
-- -- -- LEFT JOIN ACTIVITY a
-- -- -- on f.player_id = a.player_id 
-- -- -- AND a.event_date = DATE_ADD(f.first_login,INTERVAL 1 DAY);

-- -- # Write your MySQL query statement below
-- -- with first_login as (
-- -- select player_id, min(event_date) as first_date from Activity group by player_id
-- -- )
-- -- select round(SUM(case when B.player_id is not null then 1 else 0 end)/count(A.player_id),2) as fraction
-- -- from first_login A
-- -- left join Activity B on 
-- -- A.player_id=B.player_id and date_add(A.first_date, INTERVAL 1 DAY)=B.event_date

-- SELECT ROUND(
--     COUNT(DISTINCT a.player_id) /
--     (SELECT COUNT(DISTINCT player_id) FROM Activity),
-- 2) AS fraction
-- FROM Activity a
-- JOIN (
--     SELECT player_id, MIN(event_date) AS first_login
--     FROM Activity
--     GROUP BY player_id
-- ) f
-- ON a.player_id = f.player_id
-- AND a.event_date = DATE_ADD(f.first_login, INTERVAL 1 DAY);

SELECT 
    ROUND(COUNT(DISTINCT a.player_id) / (SELECT COUNT(DISTINCT player_id) FROM Activity), 2) AS fraction
FROM 
    Activity a
JOIN 
    (SELECT player_id, MIN(event_date) AS first_login
     FROM Activity
     GROUP BY player_id) temp
ON 
    a.player_id = temp.player_id 
    AND a.event_date = DATE_ADD(temp.first_login, INTERVAL 1 DAY);