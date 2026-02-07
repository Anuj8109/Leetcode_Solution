# Write your MySQL query statement below




-- select curr.customer_id from 
-- (
-- select customer_id, count(distinct product_key) as count
-- from customer 
-- group by customer_id
-- ) as curr
-- where curr.count = (
--     select count(1) 
-- from product);

select customer_id
from customer 
group by customer_id
having count(distinct product_key) = (select count(1) from product);