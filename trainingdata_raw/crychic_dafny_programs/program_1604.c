// Generated C + ACSL

typedef struct {
  int id;
  int eid;
} Employee;

/*@
    assigns \nothing;
    ensures \result.id == 0;
    ensures \result.eid == e.eid;
*/
Employee RemoveIdField(Employee e)
{
  Employee e_prime;
  e_prime.id = 0;
  e_prime.eid = e.eid;
  return e_prime;
}

/*@
    assigns \nothing;
    ensures \result.eid == 1;
    ensures \result.id == e.id;
*/
Employee AddEidField(Employee e)
{
  Employee e_prime;
  e_prime.eid = 1;
  e_prime.id = e.id;
  return e_prime;
}

/*@
    assigns \nothing;
    ensures \result.id == 0;
*/
Employee Migration(Employee e)
{
  Employee temp = RemoveIdField(e);
  //@ assert temp.id == 0;
  Employee e_prime = AddEidField(temp);
  //@ assert e_prime.id == temp.id;
  //@ assert e_prime.id == 0;
  return e_prime;
}