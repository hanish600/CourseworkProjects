-- Q1
SELECT category_name,COUNT(category_name) AS instrument_count,
MAX(list_price) AS list_price FROM categories
JOIN instruments
ON categories.category_id=instruments.category_id
GROUP BY category_name
ORDER BY instrument_count DESC;

-- Q2
SELECT email_address,sum(item_price*quantity) AS item_price_total,
sum(discount_amount*quantity) as discount_amount_total
FROM musicians
JOIN orders 
ON musicians.musician_id=orders.musician_id
JOIN order_instruments 
ON orders.order_id=order_instruments.order_id
GROUP BY email_address
ORDER BY SUM(item_price*quantity) DESC;

-- Q3

SELECT email_address,
COUNT(DISTINCT orders.order_id) AS order_count,
((sum(item_price))-(sum(discount_amount))) AS order_total
from musicians
JOIN orders
ON musicians.musician_id=orders.musician_id
join order_instruments
ON orders.order_id=order_instruments.order_id
GROUP BY email_address
HAVING COUNT(DISTINCT orders.order_id) > 1
ORDER BY order_total DESC;

-- Q4
SELECT email_address,
COUNT(*) AS order_count,
((sum(item_price))-(sum(discount_amount))) AS order_total
from musicians
JOIN orders
ON musicians.musician_id=orders.musician_id
join order_instruments
ON orders.order_id=order_instruments.order_id
WHERE item_price > 400
GROUP BY email_address
HAVING COUNT(*) > 1
ORDER BY order_total DESC;

-- Q5
SELECT instrument_name,
SUM((list_price - discount_amount) * Quantity) AS instrument_total
from instruments
JOIN order_instruments
ON instruments.instrument_id=order_instruments.instrument_id
GROUP BY instrument_name with ROLLUP;

-- Q6
Select email_address,
count(distinct order_instruments.instrument_id) as number_of_instruments
from musicians
join orders
on musicians.musician_id=orders.musician_id
join order_instruments
on orders.order_id=order_instruments.order_id
GROUP BY email_address
having count(distinct order_instruments.instrument_id) > 1
ORDER BY email_address ASC;

-- Q7
SELECT
IF(GROUPING(category_name) = 1, 'Grand Total', category_name) AS category_name,
IF(GROUPING(instrument_name) = 1, 'Category Total',instrument_name) as instrument_name,
SUM(quantity) as qty_purchased
FROM categories 
JOIN instruments
ON categories.category_id=instruments.category_id
JOIN order_instruments
on instruments.instrument_id=order_instruments.instrument_id
GROUP BY category_name,instrument_name WITH ROLLUP;

-- Q8 
SELECT
order_id,
SUM((item_price - discount_amount) * quantity) OVER(partition by item_id) as item_amount,
SUM((item_price - discount_amount) * quantity) OVER(partition by order_id) as order_amount
FROM order_instruments
ORDER BY order_id ASC;

-- Q9
SELECT
order_id,
SUM((item_price - discount_amount) * quantity) OVER(partition by item_id) as item_amount,
SUM((item_price - discount_amount) * quantity) OVER(orders
ORDER BY item_price)
as order_amount,
ROUND(AVG((item_price - discount_amount) * quantity) OVER(orders),2) as avg_order_amt
FROM order_instruments
WINDOW orders AS (PARTITION BY order_id)
ORDER BY order_id ASC,item_amount ASC;

-- Q10
SELECT 
musician_id,
order_date,
SUM((item_price - discount_amount) * quantity) OVER(partition by order_instruments.item_id) as item_total,
SUM((item_price - discount_amount) * quantity) OVER (partition by orders.musician_id) as muscician_total,
SUM((item_price - discount_amount) * quantity) OVER(PARTITION BY orders.musician_id
ORDER BY order_date
-- Peer Group
RANGE BETWEEN UNBOUNDED PRECEDING AND CURRENT ROW)
as musician_total_by_date
FROM 
orders
join order_instruments
on orders.order_id=order_instruments.order_id
order by orders.musician_id;