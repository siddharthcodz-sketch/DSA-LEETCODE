# Write your MySQL query statement below
SELECT c.name as Customers
FROM Customers c
LEFT JOIN Orders o -- <- FINAL TABLE NAME 
    ON c.id = o.customerId
WHERE customerId IS NULL;