-- Last updated: 19/08/2026, 15:34:15
-- -- # Write your MySQL query statement below
-- -- Select e.employee_id
-- -- from Employees e
-- -- left join Employees m
-- -- on e.manager_id = m.employee_id 
-- -- where e.salary < 30000
-- -- and e.manager_id is NOT NULL 
-- -- and m.employee_id is NULL
-- -- order by e.employee_id;


-- SELECT sub.employee_id
-- FROM Employees sub
-- LEFT JOIN Employees sup
--   ON sub.manager_id = sup.employee_id
-- WHERE sub.salary < 30000
--   AND (sup.employee_id IS NULL)
--   AND sub.manager_id IS NOT NULL
-- ORDER BY sub.employee_id

SELECT employee_id
FROM Employees
WHERE salary < 30000
  AND manager_id IS NOT NULL
  AND manager_id NOT IN (
      SELECT employee_id
      FROM Employees
  )
ORDER BY employee_id;