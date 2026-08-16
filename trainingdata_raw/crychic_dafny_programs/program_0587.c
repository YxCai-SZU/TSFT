// Generated C + ACSL

/*@
    requires x >= 0 && y >= 0;
    requires x <= 2147483647 - y;
    assigns \nothing;
*/
void SumMax(int x, int y)
{
  int s = (x + y);
  int m;
  /*@ assert s >= 0 && s <= 2147483647; */
  if ((x < y))
  {
    m = y;
    /*@ assert m >= 0 && m <= 2147483647; */
    /*@ assert m == y; */
  }
  else
  {
    m = x;
    /*@ assert m >= 0 && m <= 2147483647; */
    /*@ assert m == x; */
  }
  /*@ assert m == (x < y ? y : x); */
  /*@ assert m >= x && m >= y; */
}