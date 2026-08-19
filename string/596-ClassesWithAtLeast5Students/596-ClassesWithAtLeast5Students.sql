-- Last updated: 19/08/2026, 15:59:31
-- # Write your MySQL query statement below
-- Select class
-- from Courses
-- group by class
-- having count(distinct student) >= 5
select class from Courses group by class having count(class) >= 5;

