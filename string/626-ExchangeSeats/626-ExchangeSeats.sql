-- Last updated: 19/08/2026, 15:59:03
-- Select 
-- case 
-- when id%2 = 1 and id != (select max(id) from Seat) then id + 1
-- when id%2 = 0 then id-1
-- else id
-- end as id,
-- student
-- from Seat 
-- order BY id;

# Write your MySQL query statement below
With newid as
(
    Select
    lag(s.id) over (Order by id asc) as prev_id,
    lead(s.id) over (Order by id asc) forw_id,
    s.id,
    Case When s.id%2=0 THEN '1' ELSE '0' end as EvOdd,
    s.student
    from seat s
), id_reassign as(
Select Coalesce(Case when n.EvOdd=0 Then n.forw_id else n.prev_id End ,n.id) as id, 
n.student
from newid n)
Select id,student from id_reassign
order by id asc