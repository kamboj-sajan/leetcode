-- Last updated: 19/08/2026, 16:05:40
-- -- -- DELETE p1
-- -- -- FROM Person p1
-- -- -- JOIN Person p2
-- -- -- ON p1.email = p2.email
-- -- -- AND p1.id > p2.id;

-- -- DELETE FROM Person
-- -- WHERE id NOT IN (
-- --     SELECT id
-- --     FROM (
-- --         SELECT MIN(id) AS id
-- --         FROM Person
-- --         GROUP BY email
-- --     ) AS temp
-- -- );

-- # Write your MySQL query statement below
-- with cte as (
--     select id 
--     from (
--         select email, min(id) as id from Person group by email
--     )t
-- )

-- delete from Person where id not in (select * from cte);


# Write your MySQL query statement below
Delete from Person
Where id Not in (Select id From(Select Min(id) as id
From Person
Group by email) t);