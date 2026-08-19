-- Last updated: 19/08/2026, 16:05:39
-- # Write your MySQL query statement below
-- Select w1.id
-- From Weather w1
-- Join Weather w2
-- on DATEDIFF(w1.recordDate,w2.recordDate) = 1
-- Where w1.temperature > w2.temperature;

Select w1.id 
from Weather w1 
Join Weather w2 
on w2.recordDate = DATE_SUB(w1.recordDate,INTERVAL 1 DAY)
WHERE w1.temperature > w2.temperature;
