-- Last updated: 25/09/2026, 01:04:51
-- # Write your MySQL query statement below
-- Select teacher_id,
-- count(distinct subject_id) AS cnt
-- FROM Teacher
-- GROUP BY teacher_id;

# Write your MySQL query statement below
SELECT teacher_id,COUNT(DISTINCT subject_id) AS cnt
FROM Teacher
GROUP BY teacher_id;