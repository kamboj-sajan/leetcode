-- Last updated: 25/09/2026, 01:12:01
-- SELECT *
-- FROM Users
-- WHERE REGEXP_LIKE(
--     mail,
--     '^[A-Za-z][A-Za-z0-9._-]*@leetcode\\.com$',
--     'c'
-- );

# Write your MySQL query statement below
SELECT 
    user_id, 
    name, 
    mail
FROM 
    users
WHERE 
    mail REGEXP '^[a-zA-Z][a-zA-Z0-9_.-]*@leetcode\\.com$' 
    AND mail LIKE BINARY '%@leetcode.com';