DELIMITER //
DROP PROCEDURE IF EXISTS test //
CREATE PROCEDURE test()
BEGIN
	DECLARE sql_error TINYINT DEFAULT false;
    declare order_id int;
    
    declare continue handler for sqlexception
	set sql_error=true;
    
    start transaction;
    
    insert into orders 
    values (DEFAULT,3,now(),'10.00','0.00',null,4,'American Express',
    '378282246310005','04/2016',4);
    
    select LAST_INSERT_ID() into order_id;
    
    insert into order_instruments
    values (default,order_id,6,'415.00','161.85',1);
    
    insert into order_instruments
    values (default,order_id,1,'699.00','209.70',1);
    
    if sql_error=false then
		commit;
        select 'The transaction was commited.';
	else
		rollback;
        select 'The transaction was rolled back.';
	end if; 
end//
delimiter ;
call test();