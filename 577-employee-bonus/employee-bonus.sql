# Write your MySQL query statement below
SELECT name, bonus 
FROM Employee AS t1
LEFT JOIN Bonus AS t2
ON t1.empId = t2.empId
WHERE bonus < 1000 OR bonus IS null