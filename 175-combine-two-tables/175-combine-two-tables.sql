# Write your MySQL query statement below
SELECT person.firstname,person.lastname,Address.city,Address.state from person left join address on person.personid=address.personid;