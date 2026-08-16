// Generated C + ACSL

/*@
    requires \true;
    assigns \nothing;
    ensures \result == x + 1;
*/
int Two(int x)
{
  /*@ assert 1; */
  int a = (x + 1);
  /*@ assert (((!(((a - 1) == 0))) || ((x == 0))) && ((!(((x - 1) != 0))) || ((a == (x + 1))))); */
  int y;
  if (((a - 1) == 0))
  {
    y = 1;
    /*@ assert y >= 0 && y <= 2147483647; */
  }
  else
  {
    y = a;
  }
  return y;  // Dafny implicit return
}