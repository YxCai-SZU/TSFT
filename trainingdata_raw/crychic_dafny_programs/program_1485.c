// Generated C + ACSL

/*@
    requires x >= 0 && y >= 0;
    requires x + y <= 2147483647;
    assigns \nothing;
*/
void MaxSum(int x, int y)
{
  int s = (x + y);
  /*@ assert s >= 0 && s <= 2147483647; */
  int m;
  if ((x > y))
  {
    m = x;
    /*@ assert m >= 0 && m <= 2147483647; */
  }
  else
  {
    m = y;
    /*@ assert m >= 0 && m <= 2147483647; */
  }
  // TODO multiple returns
  return;
}