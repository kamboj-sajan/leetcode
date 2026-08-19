-- Last updated: 19/08/2026, 15:51:47
-- -- Select p.product_id,
-- -- COALESCE(t.new_price,10)AS price
-- -- FROM 
-- -- (
-- --     SELECT DISTINCT product_id
-- --     FROM products
-- -- ) p
-- -- LEFT JOIN 
-- -- (
-- --     select product_id, new_price
-- --     From Products
-- --     WHERE (product_id,change_date) IN
-- --     (
-- --         Select product_id,max(change_date)
-- --         FROM products
-- --         WHERE change_date <= '2019-08-16'
-- --         GROUP BY product_id
-- --     )
-- -- ) t
-- -- on p.product_id = t.product_id;

-- Select p.product_id,
-- COALESCE(t.new_price,10) AS price
-- FROM 
-- (
--     Select distinct product_id
--     FROM Products
-- )p
-- LEFT JOIN 
-- (
--     Select product_id,
--     new_price,
--     ROW_NUMBER() OVER(
--         partition BY product_id
--         ORDER BY change_date DESC
--     )as rn
--     FROM Products 
--     where change_date <= '2019-08-16'
-- ) t
-- on p.product_id = t.product_id
-- and t.rn = 1;

-- WITH LatestPrices AS (
--     SELECT 
--         product_id, 
--         new_price,
--         RANK() OVER (PARTITION BY product_id ORDER BY change_date DESC) AS ranked
--     FROM Products
--     WHERE change_date <= '2019-08-16'
-- )
-- SELECT 
--     p.product_id,
--     IFNULL(lp.new_price, 10) AS price
-- FROM (SELECT DISTINCT product_id FROM Products) p
-- LEFT JOIN LatestPrices lp 
--     ON p.product_id = lp.product_id AND lp.ranked = 1;
SELECT
  product_id,
  10 AS price
FROM
  Products
GROUP BY
  product_id
HAVING
  MIN(change_date) > '2019-08-16'
UNION ALL
SELECT
  product_id,
  new_price AS price
FROM
  Products
WHERE
  (product_id, change_date) IN (
    SELECT
      product_id,
      MAX(change_date)
    FROM
      Products
    WHERE
      change_date <= '2019-08-16'
    GROUP BY
      product_id
  )