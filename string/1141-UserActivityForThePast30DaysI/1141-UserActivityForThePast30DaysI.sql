-- Last updated: 25/09/2026, 01:16:08
# Write your MySQL query statement below
Select activity_date as day,
count(distinct user_id)as active_users
from Activity 
where activity_date between '2019-06-28' and '2019-07-27'
group BY activity_date;