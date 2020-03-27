-- Short Films

select
 movies.movie_title as 'movie_title', 
 movies.movie_year as 'movie_year', 
 concat( directors.director_first_name, directors.director_last_name)
  as 'director_name',
 concat( actors.actor_first_name, actors.actor_last_name )
  as 'actor_name',  
 movies_cast.role as 'role'
from
 movies, movies_directors, directors, movies_cast, actors

where
 directors.director_id = movies_directors.director_id
 and
 movies_directors.movie_id = movies.movie_id
 and
 movies.movie_id = movies_cast.movie_id
 and
 movies_cast.actor_id = actors.actor_id

order by movies.movie_time ASC LIMIT 1 ;

	
