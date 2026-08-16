// Generated C + ACSL

/*@
    requires \true;
    assigns \nothing;
    ensures \result <= x && \result <= y && \result <= z;
    ensures \result == x || \result == y || \result == z;
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
      /*@ assert m <= x && m <= y && m <= z; */
    }
    else
    {
      m = x;
      /*@ assert m == x; */
      /*@ assert m <= x && m <= z; */
      /*@ assert z >= x && z < y ==> m <= y; */
    }
    /*@ assert m <= y && m <= z; */
    /*@ assert m == x || m == z; */
  }
  else
  {
    m = y;
    /*@ assert m == y; */
    /*@ assert m <= y && m <= z; */
    if ((x < y))
    {
      m = x;
      /*@ assert m == x; */
      /*@ assert m <= x && m <= y; */
      /*@ assert z >= y && x < y ==> m <= z; */
    }
    /*@ assert m <= y && m <= z; */
    /*@ assert m == x || m == y; */
  }
  /*@ assert m <= x && m <= y && m <= z; */
  /*@ assert m == x || m == y || m == z; */
  return m;  // Dafny implicit return
}