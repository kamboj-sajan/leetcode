-- Last updated: 19/08/2026, 15:34:56
-- -- -- Select 'Low Salary' AS category,
-- -- -- COUNT(*) AS accounts_count
-- -- -- From Accounts
-- -- -- Where income < 20000

-- -- -- UNION ALL

-- -- -- Select 'Average Salary',
-- -- -- COUNT(*) AS accounts_count
-- -- -- From Accounts
-- -- -- Where income between 20000 and 50000

-- -- -- UNION ALL

-- -- -- Select 'High Salary',
-- -- -- COUNT(*) AS accounts_count
-- -- -- From Accounts
-- -- -- Where income > 50000;

-- -- SELECT 'Low Salary' AS category,
-- -- SUM(income < 20000)as accounts_count
-- -- From Accounts
 
-- -- UNION ALL

-- -- SELECT 'Average Salary',
-- -- sum(income between 20000 and 50000)
-- -- From Accounts

-- -- UNION ALL

-- -- SELECT 'High Salary',
-- -- SUM(income > 50000)
-- -- From Accounts

-- WITH salary_counts AS (
--     SELECT
--         SUM(income < 20000 ) AS low_count,
--         SUM(income BETWEEN 20000 AND 50000 ) AS average_count,
--         SUM(income > 50000 ) AS high_count
--     FROM Accounts
-- )

-- SELECT 'Low Salary' AS category, low_count AS accounts_count
-- FROM salary_counts

-- UNION ALL

-- SELECT 'Average Salary', average_count
-- FROM salary_counts

-- UNION ALL

-- SELECT 'High Salary', high_count
-- FROM salary_counts;

# Write your MySQL query statement below
SELECT
    'Low Salary' As category
    ,COUNT(CASE WHEN income<20000 THEN 1 END) AS accounts_count
FROM accounts

UNION ALL

SELECT
    'Average Salary' AS category
    ,COUNT(CASE WHEN income BETWEEN 20000 AND 50000 THEN 1 END) AS accounts_count
FROM accounts

UNION ALL

SELECT 
    'High Salary' AS category
    ,COUNT(CASE WHEN income>50000 THEN 1 END) AS accounts_count
FROM accounts