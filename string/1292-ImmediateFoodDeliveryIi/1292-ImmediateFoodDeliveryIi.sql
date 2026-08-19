-- Last updated: 19/08/2026, 15:51:30
-- -- # Write your MySQL query statement below
-- -- Select 
-- -- Round(
-- --     AVG(order_date = customer_pref_delivery_date) * 100,
-- --     2
-- -- )
-- -- as immediate_percentage
-- -- from Delivery
-- -- where (customer_id,order_date) IN(
-- --     select customer_id,MIN(order_date)
-- --     From delivery
-- --     group By customer_id
-- -- );

-- SELECT 
--     ROUND(
--         SUM(IF(order_date = customer_pref_delivery_date, 1, 0)) 
--         * 100.0 / COUNT(delivery_id), 
--         2
--     ) AS immediate_percentage
-- FROM Delivery
-- WHERE (customer_id, order_date) IN (
--     SELECT customer_id, MIN(order_date)
--     FROM Delivery
--     GROUP BY customer_id
-- );

# Write your MySQL query statement below
with first_order as (
    select *,
    row_number() over (
        partition by customer_id
        order by order_date
    ) as rn
from delivery ) 
select round((count( case when customer_pref_delivery_date=order_date then 1 end)/count(*))*100,2) as immediate_percentage
from first_order
where rn=1;