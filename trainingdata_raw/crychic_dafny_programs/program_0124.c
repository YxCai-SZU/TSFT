// Generated C + ACSL

/*@
    assigns \nothing;
    ensures x >= 0 ==> \result == x;
    ensures x < 0 ==> x + \result == 0;
*/
int Abs(int x)
{
  if ((x < 0))
  {
    return -x;
  }
  else
  {
    return x;
  }
}