// Generated C + ACSL

/*@
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
    /*@ assert m <= x && m <= y; */
  }
  else
  {
    m = y;
    /*@ assert m == y; */
    /*@ assert m <= x && m <= y; */
  }
  /*@ assert m == x || m == y; */
  /*@ assert m <= x && m <= y; */
  return m;  // Dafny implicit return
}