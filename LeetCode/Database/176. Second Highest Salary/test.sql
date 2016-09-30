SELECT MAX(Salary) AS SecondHighestSalary
From Employee
WHERE Salary < (
SELECT MAX(Salary)
FROM Employee
);
