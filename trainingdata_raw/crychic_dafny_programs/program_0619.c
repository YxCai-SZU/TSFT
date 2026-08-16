// Generated C + ACSL

/*@
    requires a != b;
    assigns \nothing;
    ensures (a > b ==> \result == a) && (a < b ==> \result == b);
    ensures \result == a || \result == b;
    ensures \result >= a || \result >= b;
*/
int Max(int a, int b)
{
  int m;
  if ((a > b))
  {
    m = a;
    /*@ assert m == a; */
    /*@ assert a > b; */
  }
  else
  {
    m = b;
    /*@ assert m == b; */
    /*@ assert a < b; */
  }
  /*@ assert (a > b ==> m == a) && (a < b ==> m == b); */
  return m;  // Dafny implicit return
}