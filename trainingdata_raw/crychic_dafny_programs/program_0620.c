// Generated C + ACSL

/*@
    assigns \nothing;
    ensures \result <= x && \result <= y;
    ensures \result == x || \result == y;
*/
int Min2(int x, int y)
{
  int m;
  if ((x < y))
  {
    m = x;
    /*@ assert m == x; */
    /*@ assert m < y; */
  }
  else
  {
    m = y;
    /*@ assert m == y; */
    /*@ assert m <= x; */
  }
  /*@ assert m <= x && m <= y; */
  /*@ assert m == x || m == y; */
  return m;  // Dafny implicit return
}

/*@
    assigns \nothing;
    ensures \result <= x && \result <= y && \result <= z;
    ensures \result == x || \result == y || \result == z;
*/
int Min3(int x, int y, int z)
{
  int m;
  if ((x < y))
  {
    if ((x < z))
    {
      m = x;
      /*@ assert m == x; */
      /*@ assert m < y && m < z; */
    }
    else
    {
      m = z;
      /*@ assert m == z; */
      /*@ assert m <= x && x < y; */
    }
    /*@ assert m <= x && m <= z; */
    /*@ assert x < y; */
  }
  else
  {
    if ((y < z))
    {
      m = y;
      /*@ assert m == y; */
      /*@ assert m <= x && m < z; */
    }
    else
    {
      m = z;
      /*@ assert m == z; */
      /*@ assert m <= y && y <= x; */
    }
    /*@ assert m <= y && m <= z; */
    /*@ assert y <= x; */
  }
  /*@ assert m <= x && m <= y && m <= z; */
  /*@ assert m == x || m == y || m == z; */
  return m;  // Dafny implicit return
}

/*@
    requires \true;
    assigns \nothing;
    ensures \result <= x && \result <= y && \result <= z;
    ensures \result == x || \result == y || \result == z;
*/
int Min3_bis(int x, int y, int z)
{
  int min_xy = Min2(x, y);
  /*@ assert min_xy <= x && min_xy <= y; */
  /*@ assert min_xy == x || min_xy == y; */
  int m = Min2(min_xy, z);
  /*@ assert m <= min_xy && m <= z; */
  /*@ assert m == min_xy || m == z; */
  /*@ assert min_xy <= x && min_xy <= y; */
  /*@ assert m <= x && m <= y && m <= z; */
  /*@ assert (m == min_xy && (min_xy == x || min_xy == y)) || m == z; */
  return m;  // Dafny implicit return
}