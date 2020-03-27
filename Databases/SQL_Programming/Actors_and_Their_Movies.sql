-- Actors and Thier Movies
-- See sub-query first.

select movies.movie_title as 'movie_title'
from movies, actors, movies_cast
where
 movies.movie_id = movies_cast.movie_id
 and
 movies_cast.actor_id = actors.actor_id
 and
 actors.actor_id IN
   (
    select a.actor_id
    from actors as a, movies as m, movies_cast as mc 
    where
     a.actor_id = mc.actor_id
     and
     mc.movie_id = m.movie_id 
    group by a.actor_id 
    having count(a.actor_id) > 1
   ) ;
