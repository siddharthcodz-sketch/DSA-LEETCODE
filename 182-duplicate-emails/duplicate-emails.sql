# Write your MySQL query statement below
-- SELECT email 
-- FROM Person
-- WHERE count(email)>2  -- aggregation ko direct WHERE me use ni kar sakte

SELECT email
FROM Person
GROUP BY Email
HAVING COUNT(email)>1
