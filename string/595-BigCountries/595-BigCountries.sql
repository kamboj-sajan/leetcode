-- Last updated: 19/08/2026, 15:59:36
-- # Write your MySQL query statement below
-- Select name,population,area from World where population >= 25000000 or area >= 3000000;


select name, population , area from World where area>=3000000 or population>=25000000;
