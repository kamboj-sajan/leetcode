-- Last updated: 25/09/2026, 01:10:33
-- # Write your MySQL query statement below
-- SELECT
--     user_id,
--     CONCAT(
--         UPPER(LEFT(name, 1)),
--         LOWER(SUBSTRING(name, 2))
--     ) AS name
-- FROM Users
-- ORDER BY user_id;

# Write your MySQL query statement below
SELECT 
    USER_ID,
    CONCAT(UPPER(LEFT(NAME,1)), LOWER(SUBSTRING(NAME,2,LENGTH(NAME)))) AS name
FROM
    USERS
ORDER BY
    USER_ID
