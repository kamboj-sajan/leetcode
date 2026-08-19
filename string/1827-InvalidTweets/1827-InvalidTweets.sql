-- Last updated: 19/08/2026, 15:37:14
-- # Write your MySQL query statement below
-- select tweet_id from Tweets where length(content) > 15;


-- SELECT tweet_id
-- FROM Tweets
-- WHERE CHAR_LENGTH(content) > 15;

-- SELECT tweet_id
-- FROM Tweets
-- WHERE LEN(content) > 15;

SELECT tweet_id
FROM (
    SELECT tweet_id, LENGTH(content) AS len
    FROM Tweets
) t
WHERE len > 15;