// Generated C + ACSL

/*@
    requires x >= 0 && x <= 2147483647;
    requires y >= 0 && y <= 2147483647;
    requires x + y <= 2147483647;
    assigns \nothing;
*/
void SumMax(int x, int y)
{
  int s = (x + y);
  /*@ assert s >= 0 && s <= 2147483647; */
  int m;
  if ((x < y))
  {
    m = y;
    /*@ assert m >= 0 && m <= 2147483647; */
  }
  else
  {
    m = x;
    /*@ assert m >= 0 && m <= 2147483647; */
  }
}