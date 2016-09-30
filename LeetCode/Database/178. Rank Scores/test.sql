SELECT s1.Score, (SELECT count(*)+1 from (SELECT DISTINCT(Score) from Scores) s2 WHERE s2.Score>s1.Score) Rank
From Scores s1
ORDER BY s1.Score DESC;

