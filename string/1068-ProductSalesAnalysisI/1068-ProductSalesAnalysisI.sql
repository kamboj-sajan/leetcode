-- Last updated: 25/09/2026, 01:16:52
-- # Write your MySQL query statement below
-- Select product_name , year, price from Sales as S left join Product as P on S.product_id = P.product_id;


# Write your MySQL query statement below
SELECT P.PRODUCT_NAME,S.YEAR,S.PRICE 
FROM SALES S
INNER JOIN PRODUCT P
ON S.PRODUCT_ID=P.PRODUCT_ID;