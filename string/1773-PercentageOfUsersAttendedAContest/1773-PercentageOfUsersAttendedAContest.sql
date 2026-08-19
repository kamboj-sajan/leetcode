-- Last updated: 19/08/2026, 15:38:03
-- -- # Write your MySQL query statement below
-- -- Select r.contest_id,
-- -- ROund(Sum(
-- --     case
-- --     When r.user_id is not NULL then 1
-- --     else 0
-- --     end
-- -- )*100.0/(SELECT COUNT(*) FROM Users),2) as percentage
-- -- FROM Register r
-- -- LEFT JOIN Users u
-- -- ON r.user_id = u.user_id
-- -- Group BY r.contest_id
-- -- ORDER BY percentage desc,r.contest_id asc;

-- SELECT
--     r.contest_id,
--     ROUND(
--         COUNT(r.user_id) * 100.0 /
--         (SELECT COUNT(*) FROM Users),
--         2
--     ) AS percentage
-- FROM Register r
-- GROUP BY r.contest_id
-- ORDER BY percentage DESC, contest_id ASC;

select r.contest_id, 
ROUND(count(r.user_id)*100.0/u_total.total, 2) as percentage 
from Register r cross join 
(select count(*) as total from users)u_total
group by r.contest_id, u_total.total
order by
percentage desc,
r.contest_id asc;