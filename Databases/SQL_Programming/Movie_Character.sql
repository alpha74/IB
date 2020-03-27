-- Movie Character

select 
 concat( directors.director_first_name,directors.director_last_name) as 'director_name',
 movies.movie_title as 'movie_title'
from 
 directors, movies_directors, movies, movies_cast
where
 directors.director_id = movies_directors.director_id
 and
 movies_directors.movie_id = movies.movie_id
 and
 movies.movie_id = movies_cast.movie_id
 
 and
 movies_cast.role = "SeanMaguire" ;
