// Generated C + ACSL

/*@
    requires x != y;
    assigns \nothing;
*/
void Q2_t3(int x, int y)
{
  if ((x > y))
  {
    /* unsupported stmt: big, small := x, y; */
  }
  else
  {
    /* unsupported stmt: big, small := y, x; */
  }
}

/*@
    assigns \nothing;
*/
void Q2_t4(int x, int y)
{
  if ((x > y))
  {
    /* unsupported stmt: big, small := x, y; */
  }
  else
  {
    /* unsupported stmt: big, small := y, x; */
  }
}
