-- Last updated: 19/08/2026, 16:06:02
-- -- -- # Write your MySQL query statement below
-- -- -- Select distinct max(salary) as SecondHighestSalary
-- -- -- from Employee
-- -- -- Where salary NOt in (
-- -- --     Select distinct max(salary)
-- -- --     from employee
-- -- -- )

-- -- # Write your MySQL query statement below
-- -- select max(salary) as SecondHighestSalary from Employee where salary not in (select max(salary) from Employee);

-- # Write your MySQL query statement below
-- select max(salary) as SecondHighestSalary from Employee where salary not in (select max(salary) from Employee);

# Write your MySQL query statement below
select( 
    SELECT distinct salary 
from Employee
order by salary DESC 
limit 1, 1
) as SecondHighestSalary;