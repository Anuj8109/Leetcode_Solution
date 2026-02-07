# Write your MySQL query statement below
-- select s.student_id, s.student_name, e.subject_name
-- from Examinations as e, students as s
-- where s.student_id = e.student_id;


-- select curr.student_id, curr.student_name, curr.subject_name, count(1) 
-- from (
-- select s.student_id, s.student_name, e.subject_name
-- from Examinations as e, students as s
-- where s.student_id = e.student_id
-- ) as curr
-- group by curr.subject_name, curr.student_id, curr.student_name;
-- group by 

-- select s.student_id, s.student_name, e.subject_name
-- from Examinations as e
-- FULL OUTER join students as s
-- on s.student_id = e.student_id;

SELECT stud.student_id,
       stud.student_name,
       subj.subject_name, 
       count(exam.subject_name) AS attended_exams
  FROM Students stud
      CROSS JOIN Subjects subj
      LEFT JOIN Examinations exam
          ON stud.student_id = exam.student_id
         AND subj.subject_name = exam.subject_name
 GROUP BY stud.student_id,
          stud.student_name,
          subj.subject_name
 ORDER BY stud.student_id,
          subj.subject_name;