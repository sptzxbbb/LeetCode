SELECT DISTINCT a.Num AS ConsecutiveNums
FROM Logs a, Logs b, Logs c
WHERE a.ID=b.ID+1 AND b.ID=c.ID+1 AND a.Num=b.Num AND b.Num=c.Num
