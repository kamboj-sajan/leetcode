-- Last updated: 19/08/2026, 15:52:51
-- # Write your MySQL query statement bel
-- Select p.project_id,
-- ROUND(AVG(e.experience_years),2) as average_years
-- FROM Project p
-- LEFT JOIN Employee e
-- On p.employee_id = e.employee_id
-- Group BY p.project_id;

select project_id,round(avg(experience_years),2) as average_years from Project p join Employee e on p.employee_id=e.employee_id group by project_id;
