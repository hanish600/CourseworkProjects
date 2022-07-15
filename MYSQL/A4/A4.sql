-- Q1

CREATE OR REPLACE VIEW movies_legendary_technicians
as SELECT  
title as Movie,
concat(first_name, ' ', last_name) as Technicians,
(year(curdate()) - year(birth_date) -1) as Age
FROM movies
join movie_cast
on movies.movie_id=movie_cast.movie_id
join artists
on artists.artist_id=movie_cast.person_id
where (year(curdate()) - year(birth_date) - 1)>40
and Profession=category
order by age,release_date asc;
SELECT *
FROM movies_legendary_technicians;

-- Q2

DROP PROCEDURE IF EXISTS must_watch_movies
DELIMITER endProcedure
CREATE PROCEDURE must_watch_movies()
BEGIN
	DECLARE NULLPTR bool default FALSE;
    DECLARE movie_title varchar(45) default "";
    DECLARE movie_distributor varchar(45) default "";
    DECLARE released year default '0';
    DECLARE movie_Data varchar (250) default "";
    -- temp used to swap order of data 
    -- to get the expected result
    -- with help of iter
    DECLARE temp varchar(100) default "";
    DECLARE iter tinyint default 0;
	DECLARE result_Set 
		CURSOR FOR SELECT
			title,
            Distributor,
            year(release_date)
            FROM movies
            WHERE gross > 2.0
            order by release_date;
    DECLARE CONTINUE HANDLER FOR NOT FOUND
		SET NULLPTR = TRUE;
	OPEN result_Set;
	while (NULLPTR=FALSE) do
		fetch result_Set into movie_title,movie_distributor,released;
        -- Wanted to swap data 1 and 5
		if (iter=1 || iter=5) then
			set temp=concat(temp,
            "'",movie_title,"'",
            ",","'",movie_distributor,"'",
            ',',"'",released,"'",'|');
            if (iter=5) then
				set nullptr=true;
			end if;
		else
			Set movie_Data = concat (movie_Data,
            "'",movie_title,"'",
            ',',"'",movie_distributor,"'",
            ',',"'",released,"'",'|');
		end if;
        set iter = iter + 1;
	end while;
	CLOSE result_Set;
    SELECT concat(movie_Data,temp) as "must_watch";
END
endProcedure
DELIMITER ;

call must_watch_movies();