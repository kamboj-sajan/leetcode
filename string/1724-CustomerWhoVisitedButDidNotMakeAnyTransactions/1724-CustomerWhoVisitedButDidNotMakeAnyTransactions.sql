-- Last updated: 19/08/2026, 15:38:39
-- # Write your MySQL query statement below
-- Select
-- V.customer_id ,
-- count(*) AS count_no_trans
-- from Visits as V
-- Left join Transactions T
-- on V.visit_id = T.visit_id
-- where T.visit_id is NULL
-- group by V.customer_id;

SELECT
    customer_id,
    COUNT(*) AS count_no_trans

FROM Visits v

LEFT JOIN Transactions t
    ON v.visit_id = t.visit_id

WHERE transaction_id IS NULL

GROUP BY customer_id;
