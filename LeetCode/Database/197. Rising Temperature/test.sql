SELECT w1.Id
FROM Weather w1 INNER JOIn Weather w2
On TO_DAYS(w1.Date)=TO_DAYS(w2.Date)+1 AND w1.Temperature>w2.Temperature;
