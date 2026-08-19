-- Last updated: 19/08/2026, 15:52:55
-- -- Select s.product_id,s.year as first_year,s.quantity,s.price
-- -- from Sales s
-- -- JOIN (
-- --     select product_id,min(year)as first_year
-- --     from Sales
-- --     group by product_id
-- -- ) t
-- -- on s.product_id = t.product_id
-- -- and s.year = t.first_year;


-- # Write your MySQL query statement below
-- SELECT product_id, year as first_year, quantity, price
-- FROM (
--     SELECT *,
--     DENSE_RANK() OVER(PARTITION BY product_id ORDER BY year) AS rnk
--     FROM Sales

-- ) as t
-- WHERE rnk = 1;

# Write your MySQL query statement below
select product_id, year as first_year, quantity, price from Sales
where(product_id,year)in(select product_id,min(year) from Sales group by product_id)
-- group by product_id