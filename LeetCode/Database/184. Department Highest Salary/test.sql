SELECT D.Name AS Department, E.Name AS Employee, E.Salary
FROM Employee as E, Department as D,
(SELECT MAX(Salary) as Salary, DepartmentId as DepartmentId
FROM Employee
GROUP BY DepartmentId
) F
WHERE E.Salary=F.Salary AND E.DepartmentId=F.DepartmentId AND E.DepartmentId=D.Id
