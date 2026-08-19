-- Last updated: 19/08/2026, 15:53:05
-- # Write your MySQL query statement below
-- Select product_name , year, price from Sales as S left join Product as P on S.product_id = P.product_id;


# Write your MySQL query statement below
SELECT P.PRODUCT_NAME,S.YEAR,S.PRICE 
FROM SALES S
INNER JOIN PRODUCT P
ON S.PRODUCT_ID=P.PRODUCT_ID;