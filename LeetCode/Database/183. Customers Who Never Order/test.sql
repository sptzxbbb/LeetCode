SELECT c.Name AS Customers
From Customers c
WHERE c.Id NOT IN (
SELECT CustomerId
From Orders o
)
