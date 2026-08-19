-- Last updated: 19/08/2026, 15:48:38
-- # Write your MySQL query statement below
-- (
--     Select u.name as results
--     FROM MovieRating mr
--     JOIN Users u on mr.user_id = u.user_id
--     group by mr.user_id
--     ORDER BY COUNT(*) DESC, u.name ASC
--     LIMIT 1
-- )
-- UNION ALL
-- (
--     Select m.title as results 
--     FROM MovieRating mr
--     JOIN Movies m on mr.movie_id = m.movie_id
--     WHERE mr.created_at >= '2020-02-01'
--     and mr.created_at < '2020-03-01'
--     GROUP BY mr.movie_id
--     ORDER BY AVG(mr.rating) DESC, m.title asc
--     LIMIT 1
-- );

# Write your MySQL query statement below
select name as results
from (
    select u.name,count(*) as freq
    from Users u
    left join MovieRating m
    on u.user_id=m.user_id
    group by u.user_id
    order by freq desc,name asc
    limit 1
) t1
union all
select title
from (
    select ms.title as title,avg(m.rating) as avrg
    from Movies ms
    left join MovieRating m
    on ms.movie_id=m.movie_id
    where month(m.created_at)=2 and year(m.created_at)=2020
    group by ms.movie_id
    order by avrg desc,title asc
    limit 1
) t2