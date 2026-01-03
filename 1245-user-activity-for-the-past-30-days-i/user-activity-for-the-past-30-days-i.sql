/* Write your PL/SQL query statement below */
select TO_CHAR(activity_date,'YYYY-MM-DD') day, count(distinct user_id) active_users
from Activity
where activity_date <= TO_DATE('2019-07-27', 'YYYY-MM-DD')
and activity_date >= TO_DATE('2019-06-28', 'YYYY-MM-DD')
group by activity_date