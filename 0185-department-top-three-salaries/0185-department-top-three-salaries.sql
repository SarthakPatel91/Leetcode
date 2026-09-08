# Write your MySQL query statement below
select department.name as department,
 employee.name as employee,
employee.salary
from employee,department
where
employee.departmentid=department.id
and
 (
    select count(distinct employee2.salary)
    from employee employee2
    where employee2.departmentid=department.id
    and employee2.salary>employee.salary
)<3;