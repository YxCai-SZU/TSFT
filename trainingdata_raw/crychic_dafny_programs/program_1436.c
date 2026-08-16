// Generated C + ACSL

/*@
    requires \true;
    assigns \nothing;
    ensures \result >= a;
    ensures \result >= b;
    ensures \result == a || \result == b;
*/
int Max(int a, int b)
{
  if ((a > b))
  {
    return a;
  }
  else
  {
    return b;
  }
}