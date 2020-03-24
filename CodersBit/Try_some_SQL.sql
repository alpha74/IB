Ans: 14

- For Each entry in first output, add number of count `manager` occurs in second query output.

- Query without count():

    -> select *
    -> from ( ( select borrower, manager from records ) as s
    -> natural join ( select manager, amount from records ) as t ) ;
    
    +-------------+----------+--------+
    | manager     | borrower | amount |
    +-------------+----------+--------+
    | manoranjan  | shubham  |  10000 |
    | manoranjan  | gurpreet |  10000 |
    | manoranjan  | ramesh   |  10000 |
    | ramgopal    | abizer   |   5000 |
    | ramgopal    | aman     |   5000 |
    | manoranjan  | shubham  |   7000 |
    | manoranjan  | gurpreet |   7000 |
    | manoranjan  | ramesh   |   7000 |
    | ramgopal    | abizer   |    300 |
    | ramgopal    | aman     |    300 |
    | manoranjan  | shubham  |   1290 |
    | manoranjan  | gurpreet |   1290 |
    | manoranjan  | ramesh   |   1290 |
    | adhikranjan | suresh   |   6500 |
    +-------------+----------+--------+

- First sub-query:
  -> select borrower, manager from records ;
  
    +----------+-------------+
    | borrower | manager     |
    +----------+-------------+
    | shubham  | manoranjan  |
    | abizer   | ramgopal    |
    | gurpreet | manoranjan  |
    | aman     | ramgopal    |
    | ramesh   | manoranjan  |
    | suresh   | adhikranjan |
    +----------+-------------+
  
  
- Second sub-query:
  -> select manager, amount from records ;
  
    +-------------+--------+
    | manager     | amount |
    +-------------+--------+
    | manoranjan  |  10000 |
    | ramgopal    |   5000 |
    | manoranjan  |   7000 |
    | ramgopal    |    300 |
    | manoranjan  |   1290 |
    | adhikranjan |   6500 |
    +-------------+--------+
  
