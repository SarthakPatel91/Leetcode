# Write your MySQL query statement below
select department.name as department,
employee.name as employee ,
employee.salary
from employee,department
where 
employee.departmentid=department.id
and
salary=(
    select max(salary) from employee
    where employee.departmentid=department.id
);