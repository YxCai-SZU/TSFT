// Generated C + ACSL

/*@
    requires x >= 0;
    requires y >= 0;
    assigns \nothing;
    ensures \result == x * y;
*/
int Mult(int x, int y)
{
  int m = x;
  int n = y;
  int r = 0;
  /*@ assert r >= 0 && r <= 2147483647; */
/*@
  loop invariant m * n + r == \at(x, Pre) * \at(y, Pre);
  loop invariant m >= 0;
  loop invariant m <= \at(m, LoopEntry);
  loop invariant r == \at(r, LoopEntry) + (\at(m, LoopEntry) - m) * n;
  loop assigns m, r;
  loop variant m;
*/
  while ((m > 0))
    {
      r = (r + n);
      m = (m - 1);
    }
  return r;
}
