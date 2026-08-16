// Generated C + ACSL

/*@
    requires \true;
    assigns \nothing;
    ensures \result <= x && \result <= y;
    ensures \result == x || \result == y;
*/
int Min(int x, int y)
{
  int m;
  if ((x <= y))
  {
    m = x;
    /*@ assert m == x; */
    /*@ assert x <= y; */
  }
  else
  {
    m = y;
    /*@ assert m == y; */
    /*@ assert x > y; */
  }
  /*@ assert (x <= y ==> m == x) && (x > y ==> m == y); */
  /*@ assert (m == x && x <= y) || (m == y && x > y); */
  return m;  // Dafny implicit return
}