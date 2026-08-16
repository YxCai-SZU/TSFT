// Generated C + ACSL

/*@
    requires \true;
    assigns \nothing;
    ensures \result <= x && \result <= y && \result <= z;
*/
int A8Q1(int x, int y, int z)
{
  int m;
  if ((z < y))
  {
    if ((z < x))
    {
      m = z;
      /*@ assert m == z; */
      /*@ assert z < x && z < y; */
      /*@ assert m <= x && m <= y && m <= z; */
    }
    else
    {
      m = x;
      /*@ assert m == x; */
      /*@ assert x <= z && z < y; */
      /*@ assert m <= x && m <= y && m <= z; */
    }
  }
  else
  {
    m = y;
    /*@ assert m == y; */
    /*@ assert y <= z; */
    if ((x < y))
    {
      m = x;
      /*@ assert m == x; */
      /*@ assert x < y && y <= z; */
      /*@ assert m <= x && m <= y && m <= z; */
    }
    else
    {
      /*@ assert m == y; */
      /*@ assert y <= x && y <= z; */
      /*@ assert m <= x && m <= y && m <= z; */
    }
  }
  /*@ assert m <= x && m <= y && m <= z; */
  return m;  // Dafny implicit return
}