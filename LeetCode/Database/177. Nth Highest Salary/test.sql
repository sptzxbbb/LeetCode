CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
DECLARE N1 INT;
set N1=N-1;
RETURN (
# Write your MySQL query statement below.
SELECT DISTINCT Salary
FROM Employee
ORDER BY Salary DESC
LIMIT N1,1
);
END
