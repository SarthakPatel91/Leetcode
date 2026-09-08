SELECT department.name AS department,
       employee.name AS employee,
       employee.salary
FROM employee, department
WHERE employee.departmentId = department.id
AND employee.salary = (
    SELECT MAX(employee.salary)
    FROM employee
    WHERE employee.departmentId = department.id
);