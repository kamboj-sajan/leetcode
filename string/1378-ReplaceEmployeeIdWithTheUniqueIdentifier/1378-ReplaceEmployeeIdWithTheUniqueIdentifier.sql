-- Last updated: 25/09/2026, 01:13:19
-- # Write your MySQL query statement below
-- select unique_id , name from EmployeeUNI as U Right join Employees as E on U.id = E.id;

 SELECT unique_id,name
 FROM Employees E LEFT JOIN
 EmployeeUNI U 
 ON E.id = U.id;