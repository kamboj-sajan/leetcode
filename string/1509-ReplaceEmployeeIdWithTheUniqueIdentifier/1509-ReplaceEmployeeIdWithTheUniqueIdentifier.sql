-- Last updated: 19/08/2026, 15:48:17
-- # Write your MySQL query statement below
-- select unique_id , name from EmployeeUNI as U Right join Employees as E on U.id = E.id;

 SELECT unique_id,name
 FROM Employees E LEFT JOIN
 EmployeeUNI U 
 ON E.id = U.id;