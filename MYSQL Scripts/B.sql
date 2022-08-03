-- Q1
SELECT customer_last_name,
customer_city, customer_zip
FROM customers
where (customer_state='IL')
ORDER BY customer_last_name DESC;

-- Q2
SELECT CONCAT(rep_last_name,', ',rep_first_name)
AS 'Representative Full Name'
FROM sales_reps
WHERE rep_last_name regexp '^Mar';

-- Q3
SELECT rep_last_name as "Representative Last name", 
sales_year as "Year of sales",
sales_total as "Total sales"
FROM sales_reps reps1
JOIN sales_totals total1
ON reps1.rep_id=total1.rep_id;


-- Q4
SELECT rep_id as "Representative ID",
Max(sales_total) as "Highest sales of Representative"
FROM sales_totals
WHERE sales_total > 900000
GROUP BY rep_id;

-- Q5
UPDATE sales_totals
SET sales_total=2345.56
WHERE (rep_id=4 and sales_year=2017);
SELECT * FROM sales_totals
WHERE (
NOT ISNULL(rep_id) and
NOT ISNULL(sales_total) and
NOT ISNULL(sales_year)
);

-- Q6
SELECT 
rep_id as "Representative ID",
sales_year as "Year of sales",
sales_total as "Total sales"
FROM sales_totals
WHERE sales_total =
(SELECT min(sales_total)
FROM (sales_totals))