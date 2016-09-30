SELECT a.Name AS Employee
FROM Employee a, Employee b
WHERE a.ManagerID=b.Id AND a.Salary>b.Salary;
