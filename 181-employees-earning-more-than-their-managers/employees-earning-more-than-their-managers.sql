# Write your MySQL query statement below
-- select emp.name Employee from Employee emp
-- where emp.managerId is not null and emp.salary > (select mng.salary from Employee mng where mng.id = emp.managerId)

select emp.name Employee from Employee emp
join employee mng
on mng.id = emp.managerId 
and mng.salary < emp.salary