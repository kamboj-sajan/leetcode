-- Last updated: 19/08/2026, 15:31:25
-- # Write your MySQL query statement below
-- Select teacher_id,
-- count(distinct subject_id) AS cnt
-- FROM Teacher
-- GROUP BY teacher_id;

# Write your MySQL query statement below
SELECT teacher_id,COUNT(DISTINCT subject_id) AS cnt
FROM Teacher
GROUP BY teacher_id;