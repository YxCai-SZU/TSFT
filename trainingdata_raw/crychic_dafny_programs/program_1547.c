// Generated C + ACSL

/*@
    axiomatic NaturalPredicate {
        predicate Natural(integer x)
            reads \nothing;
        axiom Natural_zero:
            Natural(0);
        axiom Natural_succ:
            \forall integer x; x > 0 ==> (Natural(x) <==> Natural(x - 1));
        axiom Natural_negative:
            \forall integer x; x < 0 ==> !Natural(x);
    }
*/

/*@
    requires x >= 0;
    decreases x;
    assigns \nothing;
    ensures \result != 0 <==> Natural(x);
*/
int Natural(int x)
{
  if (x == 0) {
    return 1;
  }
  /*@ assert x > 0; */
  /*@ assert Natural(x) <==> Natural(x - 1); */
  return Natural((x - 1));
}

/*@
    requires x > 0;
    decreases x;
    assigns \nothing;
    ensures (x != 0) ==> (\result != 0);
    ensures \result != 0;
*/
int Positive(int x)
{
  if (x != 0) {
    /*@ assert x > 0; */
    return 1;
  }
  return 0;
}

/*@
    assigns \nothing;
    ensures \result == ((x <= y) ? x : y);
    ensures \result <= x;
    ensures \result <= y;
    ensures \result == x || \result == y;
*/
int least(int x, int y)
{
  int least_val;
  int greatest_val;
  
  if (x < y) {
    least_val = x;
    greatest_val = y;
  } else {
    least_val = y;
    greatest_val = x;
  }
  
  /*@ assert x < y ==> least_val == x; */
  /*@ assert x >= y ==> least_val == y; */
  /*@ assert least_val == ((x <= y) ? x : y); */
  
  return least_val;
}

/*@
    assigns \nothing;
    ensures \result == (x >= y ? x : y);
    ensures \result >= x;
    ensures \result >= y;
    ensures \result == x || \result == y;
*/
int greatest(int x, int y)
{
  int least_val;
  int greatest_val;
  
  if (x < y) {
    least_val = x;
    greatest_val = y;
  } else {
    least_val = y;
    greatest_val = x;
  }
  
  /*@ assert x < y ==> greatest_val == y; */
  /*@ assert x >= y ==> greatest_val == x; */
  /*@ assert greatest_val == (x >= y ? x : y); */
  
  return greatest_val;
}

/*@
    assigns \nothing;
*/
void mixmax(int x, int y)
{
  if ((x < y))
  {
    // least = x, greatest = y
    /*@ assert x < y; */
  }
  else
  {
    // least = y, greatest = x
    /*@ assert x >= y; */
  }
}