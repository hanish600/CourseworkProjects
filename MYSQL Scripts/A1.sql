-- Q1
SELECT instrument_name,list_price,date_added
FROM instruments 
WHERE list_price between 500 and 2000
ORDER BY date_added DESC;

-- Q2
SELECT item_id,item_price,discount_amount,quantity,
item_price*quantity AS price_total,
discount_amount*quantity AS discount_total,
(item_price - discount_amount)*quantity AS item_total
FROM order_instruments
WHERE (item_price - discount_amount)*quantity > 500
ORDER BY item_total DESC;

-- Q3
SELECT 
DATE_FORMAT(NOW(),NOW()) AS today_unformatted,
DATE_FORMAT(NOW(),'%e-%b-%y') AS today_formatted;
-- SELECT DATE_FORMAT(NOW(),'%e/%m/%y') AS third_format;
-- SELECT DATE_FORMAT(NOW(), '%D %M %Y') AS forth_format;

-- Q4
SELECT first_name,last_name,line1,city,state,zip_code
FROM addresses 
INNER JOIN musicians
on addresses.musician_id=musicians.musician_id
WHERE email_address = 'david.goldstein@hotmail.com';

-- Q5
SELECT first_name,last_name,line1,city,state,zip_code
FROM addresses
INNER JOIN musicians
on addresses.musician_id=musicians.musician_id
where address_id = billing_address_id;

-- Q6
SELECT last_name,first_name,order_date,
instrument_name,item_price,discount_amount,quantity
FROM musicians a1
INNER JOIN orders a2
ON a1.musician_id = a2.musician_id
INNER JOIN order_instruments a3
ON a3.order_id = a2.order_id
INNER JOIN instruments a4
ON a4.instrument_id = a3.instrument_id
ORDER BY last_name,order_date,instrument_name;

-- Q7
SELECT a1.instrument_name,a2.list_price
FROM instruments a1, instruments a2
WHERE a1.instrument_id != a2.instrument_id
and a1.list_price = a2.list_price
ORDER BY instrument_name;

 -- Q8
SELECT 'NOT SHIPPED' AS ship_status,order_id,order_date from orders
WHERE STR_TO_DATE(ship_date, '%Y-%m-%d') IS NULL
UNION
SELECT 'SHIPPED' AS ship_status,order_id,order_date from orders
WHERE STR_TO_DATE(ship_date, '%Y-%m-%d') IS NOT NULL
ORDER BY order_id,order_date;