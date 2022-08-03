DELIMITER //
DROP PROCEDURE IF EXISTS test //
CREATE PROCEDURE test()
BEGIN
	DECLARE sql_error TINYINT DEFAULT false;
    
    declare continue handler for sqlexception
	set sql_error=true;
    
    start transaction;
    
    select * from musicians 
    where musician_id=6
    for update;
    
    update orders
    set musician_id=3
    where musician_id=6;
    
    update addresses
    set musician_id=3
    where musician_id=6;
    
    delete from musicians where musician_id=6;
    
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