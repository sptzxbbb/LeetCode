SELECT D.Name Department, E.Name Employee, E.Salary Salary
FROM Employee E, Department D
WHERE E.DepartmentID=D.Id AND
(SELECT COUNT(DISTINCT(Salary))
FROM Employee
WHERE DepartmentId=E.DepartmentId AND Salary > E.Salary) < 3
ORDER BY E.DepartmentId, E.Salary DESC;
