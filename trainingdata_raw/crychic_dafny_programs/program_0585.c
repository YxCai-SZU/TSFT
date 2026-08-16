// Generated C + ACSL

/*@
    assigns \nothing;
    ensures 0 <= x ==> \result == x;
    ensures x < 0 ==> \result == -x;
    ensures 0 <= \result;
*/
int Abs(int x)
{
  int y;
  if ((x < 0))
  {
    y = -x;
    /*@ assert y >= 0 && y <= 2147483647; */
  }
  else
  {
    y = x;
  }
  return y;  // Dafny implicit return
}