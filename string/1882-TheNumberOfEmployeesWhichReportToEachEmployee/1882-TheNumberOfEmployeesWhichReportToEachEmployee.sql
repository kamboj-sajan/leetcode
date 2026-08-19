-- Last updated: 19/08/2026, 15:36:52
-- # Write your MySQL query statement below
-- select m.employee_id,
-- m.name,
-- count(e.employee_id)as reports_count,
-- round(avg(e.age))as average_age
-- From Employees e
-- jOIN Employees m
-- on e.reports_to = m.employee_id
-- group BY m.employee_id,m.name
-- order by m.employee_id;

select 
    a.employee_id,
    a.name,
    count(b.reports_to) as reports_count,
    round(avg(b.age),0) as average_age
from Employees a
inner join Employees b on a.employee_id=b.reports_to
group by 1
order by 1