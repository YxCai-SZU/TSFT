// Generated C + ACSL

/*@
    requires \true;
    assigns \nothing;
    ensures \result >= 0;
    ensures \result == x || \result == -x;
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