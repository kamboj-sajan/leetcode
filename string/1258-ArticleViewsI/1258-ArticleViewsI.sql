-- Last updated: 19/08/2026, 15:51:49
-- # Write your MySQL query statement below
-- Select distinct author_id as id from Views where author_id = viewer_id order by author_id ;


# Write your MySQL query statement below
select distinct author_id as id
from Views
WHERE author_id = viewer_id 
-- took hint of this above line ...this is there bcoz of the line:"authors that viewed at least one of their own articles"
order by author_id ASC;