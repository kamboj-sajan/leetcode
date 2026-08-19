-- Last updated: 19/08/2026, 15:59:52
-- # Write your MySQL query statement below
-- select E.name , B.bonus from Employee E LEFT JOIN Bonus B ON E.empId = B.empId WHERE B.bonus < 1000 or B.bonus is NULL;
# Write your MySQL query statement below
SELECT
    e.name,
    b.bonus
FROM Employee e
LEFT JOIN Bonus b
ON e.empId = b.empId
WHERE b.bonus < 1000
   OR b.bonus IS NULL;