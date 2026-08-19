-- Last updated: 19/08/2026, 15:59:12
-- # Write your MySQL query statement below
-- Select c.id , c.movie ,c.description,c.rating
-- FROm Cinema c
-- Where c.description != 'boring' AND c.id%2 != 0
-- order BY c.rating desc;

# Write your MySQL query statement below
select *
from Cinema
having (id%2=1) and description != 'boring'
order by rating desc