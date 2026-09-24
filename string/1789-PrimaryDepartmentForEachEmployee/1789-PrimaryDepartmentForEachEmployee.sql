-- Last updated: 25/09/2026, 01:09:38
-- -- -- SELECT employee_id, department_id
-- -- -- FROM Employee
-- -- -- WHERE primary_flag = 'Y'
-- -- --    OR employee_id IN (
-- -- --         SELECT employee_id
-- -- --         FROM Employee
-- -- --         GROUP BY employee_id
-- -- --         HAVING COUNT(*) = 1
-- -- --    );

-- -- select a.employee_id, a.department_id
-- -- from 
-- -- (SELECT 
-- --   *, 
-- --   COUNT(employee_id) OVER(PARTITION BY employee_id) AS EmployeeCount 
-- -- FROM 
-- --   Employee) a
-- --   where a.EmployeeCount = 1 OR a.primary_flag = "Y";

-- SELECT
--     employee_id,
--     department_id
-- FROM Employee
-- WHERE primary_flag = 'Y'

-- UNION

-- SELECT
--     employee_id,
--     department_id
-- FROM Employee
-- GROUP BY employee_id
-- HAVING COUNT(*) = 1;

# Write your MySQL query statement below
SELECT employee_id,department_id from Employee where primary_flag = 'Y'
UNION
SELECT employee_id,department_id from Employee where employee_id NOT IN
(
    SELECT employee_id from Employee where primary_flag = 'Y'
)