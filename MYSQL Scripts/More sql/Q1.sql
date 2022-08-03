DELIMITER //
DROP PROCEDURE IF EXISTS test //
CREATE PROCEDURE test()
BEGIN
	DECLARE sql_error TINYINT DEFAULT false;
    
    declare continue handler for sqlexception
	set sql_error=true;
    
    start transaction;
    
    -- remove foreign keys first
    delete from addresses where musician_id=8;
    delete from musicians where musician_id = 8;
    
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
select * from musicians;
select * from addresses;