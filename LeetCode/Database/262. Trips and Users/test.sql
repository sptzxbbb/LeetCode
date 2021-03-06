SELECT Request_at Day,
ROUND(SUM(IF(t.Status='completed', 0, 1)) / COUNT(*), 2) AS "Cancellation Rate"
FROM Trips t INNER JOIN Users u
ON t.Client_Id=u.Users_Id
WHERE t.Request_at BETWEEN '2013-10-01' AND '2013-10-03'
AND u.Banned='No' AND u.Role='client'
GROUP BY t.Request_at
ORDER BY t.Request_at;


