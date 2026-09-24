-- Last updated: 25/09/2026, 01:14:19
SELECT 
s.student_id,
s.student_name,
sub.subject_name,
Count(e.subject_name) AS attended_exams
FROm Students s
CROSS JOIN Subjects sub
LEFT JOIN Examinations e
ON s.student_id = e.student_id
AND sub.subject_name = e.subject_name
GROUP BY
s.student_id,
s.student_name,
sub.subject_name
ORDER BY
s.student_id,
sub.subject_name;