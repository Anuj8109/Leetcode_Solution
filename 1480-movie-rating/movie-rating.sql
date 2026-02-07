# Write your MySQL query statement below

(select name as results from (
    select user_id, count(1) as count
    from movieRating
    group by user_id
) as userGroup, Users
where userGroup.user_id = Users.user_id
order by count desc, users.name 
limit 1)
UNION ALL
(select m.title as results from 
movies m, MovieRating mr
where m.movie_id = mr.movie_id 
and created_at >= '2020-02-01' and
 created_at <= '2020-02-29'
 GROUP BY  m.title
order by avg(mr.rating) desc, m.title
limit 1);

-- select r1.results, r2.results from 
-- (select name as results from (
--     select user_id, count(1) as count
--     from movieRating
--     group by user_id
-- ) as userGroup, Users
-- where userGroup.user_id = Users.user_id
-- order by count desc, users.name 
-- limit 1) as r1,
--  (select m.title as results from 
-- movies m, MovieRating mr
-- where m.movie_id = mr.movie_id 
-- and created_at >= '2020-02-01' and
--  created_at <= '2020-02-29'
-- order by mr.rating desc
-- limit 1) as r2;