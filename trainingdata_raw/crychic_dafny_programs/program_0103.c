// Generated C + ACSL

/*@
    assigns \nothing;
    ensures x <= y ==> \result == x;
    ensures x > y ==> \result == y;
*/
int Min(int x, int y)
{
  if ((x < y))
  {
    return x;
  }
  else
  {
    return y;
  }
}