-- Last updated: 19/08/2026, 15:34:48
-- # Write your MySQL query statement below
-- Select s.user_id , 
-- Round(
--     (Avg(
--         Case
--         when c.action = 'confirmed' then 1
--         else 0
--         end
--     ),0),2
-- )As confirmation_rate
-- From Signups s
-- Left join Confirmations c
-- ON s.user_id = c.user_id
-- GRoup BY s.user_id;


SELECT 
s.user_id,
ROUND(
    IFNULL(Sum(c.action = 'confirmed')/COUNT(c.action),
    0),2
)AS confirmation_rate
FROM Signups s
Left JOIN Confirmations c
On s.user_id = c.user_id
GROUP BY s.user_id;