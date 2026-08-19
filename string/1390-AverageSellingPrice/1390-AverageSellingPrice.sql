-- Last updated: 19/08/2026, 15:50:13
-- # Write your MySQL query statement below
-- Select p.product_id,
-- ROUND(
--     IFNULL(SUm(p.price * u.units)/SUM(u.units),0),2
-- ) as average_price
-- From Prices p
-- LEFT JOIN UnitsSold u
-- ON p.product_id = u.product_id
-- AND u.purchase_date BETWEEN p.start_date and p.end_date
-- GROUP BY p.product_id;

# Write your MySQL query statement below
select p.product_id , COALESCE(ROUND(sum(p.price * u.units)/sum(u.units),2),0) average_price
from prices p
left join unitssold u
on p.product_id = u.product_id
where (u.purchase_date >= p.start_date and 
u.purchase_date <= p.end_date)
OR u.purchase_date is null
group by p.product_id;

-- select * from prices p 
-- left join 
-- unitssold u
-- on p.product_id = u.product_id
-- where u.purchase_date >= p.start_date and 
-- u.purchase_date < p.end_date;