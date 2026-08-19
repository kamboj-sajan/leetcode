-- Last updated: 19/08/2026, 15:50:58
-- -- -- # Write your MySQL query statement below
-- -- -- Select DATE_FORMAT(trans_date,'20%y-%m') as month,
-- -- -- country,
-- -- -- count(state)as trans_count,
-- -- -- sum(
-- -- --     case when state = 'approved' then 1
-- -- --     else 0
-- -- --     end
-- -- -- )as approved_count,
-- -- -- sum(amount)as trans_total_amount,
-- -- -- sum(
-- -- --     case
-- -- --     when state = 'approved' then amount
-- -- --     else 0
-- -- --     end 
-- -- -- )as approved_total_amount
-- -- -- from Transactions
-- -- -- group by month,country
-- -- -- order by month,country;

-- -- # Write your MySQL query statement below
-- -- SELECT 
-- --     LEFT(trans_date, 7) AS month,
-- --     country, 
-- --     COUNT(id) AS trans_count,
-- --     SUM(state = 'approved') AS approved_count,
-- --     SUM(amount) AS trans_total_amount,
-- --     SUM((state = 'approved') * amount) AS approved_total_amount
-- -- FROM 
-- --     Transactions
-- -- GROUP BY 
-- --     month, country;

-- -- 2026 - 07 - 18

-- SELECT
--     DATE_FORMAT(trans_date, "%Y-%m") AS month,
--     country,
--     COUNT(id) AS trans_count,
--     SUM(CASE WHEN state = "approved" THEN 1 ELSE 0 END) AS approved_count,
--     SUM(amount) AS trans_total_amount,
--     SUM(CASE WHEN state = "approved" THEN amount ELSE 0 END) AS approved_total_amount
-- FROM
--     Transactions
-- GROUP BY
--     month,
--     country

SELECT
    DATE_FORMAT(trans_date, '%Y-%m') AS month,
    country,
    COUNT(*) AS trans_count,
    SUM(state = 'approved') AS approved_count,
    SUM(amount) AS trans_total_amount,
    SUM(CASE
            WHEN state = 'approved' THEN amount
            ELSE 0
        END) AS approved_total_amount
FROM Transactions
GROUP BY DATE_FORMAT(trans_date, '%Y-%m'), country;