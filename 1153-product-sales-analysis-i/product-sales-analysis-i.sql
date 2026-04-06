# Write your MySQL query statement below
SELECT product_name, year, price
FROM Sales AS t1
JOIN Product AS t2
ON t1.product_id = t2.product_id