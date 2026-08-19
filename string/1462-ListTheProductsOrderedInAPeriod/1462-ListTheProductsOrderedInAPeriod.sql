-- Last updated: 19/08/2026, 15:48:59
-- -- # Write your MySQL query statement below
-- -- Select p.product_name,
-- -- sum(m.unit)as unit
-- -- from Products p
-- -- LEFT JOIN Orders m
-- -- ON p.product_id = m.product_id
-- -- where m.order_date between '2020-02-01' and '2020-02-29'
-- -- group by p.product_id
-- -- having sum(m.unit) >= 100;

-- # Write your MySQL query statement below

-- SELECT
--     P.product_name,
--     SUM(O.unit) AS unit
-- FROM Products P
-- JOIN Orders O
-- ON P.product_id = O.product_id
-- WHERE O.order_date LIKE '2020-02%'
-- GROUP BY P.product_id, P.product_name
-- HAVING SUM(O.unit) >= 100;

-- SELECT p.product_name, SUM(o.unit) AS unit
-- FROM Products p INNER JOIN Orders o
-- ON p.product_id = o.product_id
-- WHERE o.order_date >= '2020-02-01' AND o.order_date < '2020-03-01'
-- GROUP BY p.product_id, p.product_name
-- HAVING SUM(o.unit) >= 100;


SELECT product_name, SUM(unit) AS unit
FROM Products INNER JOIN Orders USING(product_id)
WHERE MONTH(order_date) = 2 AND YEAR(order_date) = 2020
GROUP BY product_name
HAVING unit >= 100;