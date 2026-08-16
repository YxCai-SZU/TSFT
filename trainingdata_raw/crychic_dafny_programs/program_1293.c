// Generated C + ACSL

/*@
    requires 0 < x;
    requires 0 < y;
    assigns \nothing;
    ensures \result > 0;
    ensures \result <= x;
    ensures \result <= y;
*/
int GCD(int x, int y)
{
  int a = x;
  int b = y;
  int r;
/*@
  loop invariant \at(x, LoopEntry) >= a >= 0 && \at(y, LoopEntry) >= b >= 0;
  loop invariant a == 0 ==> \at(y, LoopEntry) >= b > 0 && \at(x, LoopEntry) >= b;
  loop invariant b == 0 ==> \at(x, LoopEntry) >= a > 0 && \at(y, LoopEntry) >= a;
  loop assigns a, b;
  loop variant a + b;
*/
  while (((a > 0) && (b > 0)))
    {
      if ((a > b))
      {
        a = (a - b);
      }
      else
      {
        b = (b - a);
      }
    }
  if ((a > 0))
  {
    r = a;
    /*@ assert r >= 0 && r <= 2147483647; */
  }
  else
  {
    r = b;
  }
  return r;  // Dafny implicit return
}