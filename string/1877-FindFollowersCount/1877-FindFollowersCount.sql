-- Last updated: 19/08/2026, 15:36:54
-- # Write your MySQL query statement below
-- Select user_id,
-- count(user_id)as followers_count
-- from Followers
-- group by user_id
-- order by user_id;

# Write your MySQL query statement below
SELECT user_id, COUNT(follower_id) AS followers_count
FROM Followers
GROUP BY user_id
ORDER BY user_id;