-- Last updated: 19/08/2026, 15:47:10
-- Select sell_date,
-- count(DISTINCT product)as num_sold,
-- GROUP_CONCAT(DISTINCT product order by product SEPARATOR ',')as products
-- FROM Activities
-- Group BY sell_date
-- order by sell_date;

SELECT  
    sell_date,
    COUNT(DISTINCT product )AS num_sold,
    GROUP_CONCAT(
        DISTINCT product
        ORDER BY product
        SEPARATOR ','
    )AS products
FROM 
    Activities 
GROUP BY 
    sell_date
ORDER BY 
    sell_date ; 