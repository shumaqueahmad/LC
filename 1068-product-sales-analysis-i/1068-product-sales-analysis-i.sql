# Write your MySQL query statement below
select p.product_name, s.year, s.price  from Sales as s inner join Product as p using(product_id); 