// Generated C + ACSL

/*@
    requires y >= 0;
    requires x + y <= 2147483647;
    requires x >= -2147483648;
    assigns \nothing;
    ensures \result == x + y;
*/
int Add(int x, int y)
{
  int r = x;
  /*@ assert x >= -2147483648 && x <= 2147483647; */
  /*@ assert x + y <= 2147483647; */
  int n = y;
/*@
  loop invariant 0 <= n <= \at(n, LoopEntry);
  loop invariant r == \at(r, LoopEntry) + (\at(n, LoopEntry) - n);
  loop invariant r == \at(x, Pre) + \at(y, Pre) - n;
  loop invariant r >= \at(x, Pre);
  loop invariant r <= \at(x, Pre) + \at(y, Pre);
  loop invariant r + n == \at(x, Pre) + \at(y, Pre);
  loop invariant r <= 2147483647;
  loop invariant r >= -2147483648;
  loop assigns r, n;
  loop variant n;
*/
  while ((n != 0))
    {
      r = (r + 1);
      n = (n - 1);
    }
  return r;  // Dafny implicit return
}