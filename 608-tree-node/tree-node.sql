# Write your MySQL query statement below
select id,
CASE 
    when p_id is NULL THEN 'Root'
    when id in (select distinct p_id from Tree) Then 'Inner'
    ELSE 'Leaf'
END as type
from Tree;