-- Last updated: 19/08/2026, 15:59:55
-- # Write your MySQL query statement below
-- Select e1.name 
-- From Employee e1 
-- JOIn Employee e2
-- ON e1.id = e2.managerID
-- GROUP BY e1.id,e1.name
-- HAVING COUNT(*) >= 5;

# Write your MySQL query statement below
SELECT e.name
FROM Employee e
JOIN (
    SELECT managerId
    FROM Employee
    WHERE managerId IS NOT NULL
    GROUP BY managerId
    HAVING COUNT(*) >= 5
) m
ON e.id = m.managerId;