-- Last updated: 25/09/2026, 01:16:54
-- Select customer_id
-- from Customer 
-- group by customer_id
-- having count(DISTINCT product_key) = (
--     SELECT count(*)
--     from Product
-- );

with cte1 as
(
    select distinct customer_id, product_key from customer
)

select customer_id from cte1 group by customer_id having count(product_key)=(select count(product_key) from Product);