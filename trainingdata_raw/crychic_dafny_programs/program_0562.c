// Generated C + ACSL

/*@
    requires \true;
    assigns \nothing;
    ensures a < b ==> \result == b;
    ensures b <= a ==> \result == a;
*/
int Max(int a, int b)
{
  if ((a < b))
  {
    return b;
  }
  else
  {
    return a;
  }
}