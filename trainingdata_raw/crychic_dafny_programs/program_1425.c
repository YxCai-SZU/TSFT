// Generated C + ACSL

/*@
    requires y >= 0;
    requires x + y <= 2147483647;
    requires x + y >= -2147483648;
    assigns \nothing;
    ensures \result == x + y;
*/
int Add(int x, int y)
{
  int r = x;
  /*@ assert r == x; */
  /*@ assert y >= 0; */
  /*@ assert x + y <= 2147483647; */
  int n = y;
/*@
  loop invariant 0 <= n <= y;
  loop invariant r == x + (y - n);
  loop invariant r + n == x + y;
  loop invariant r <= 2147483647;
  loop invariant r >= -2147483648;
  loop invariant r + n <= 2147483647;
  loop invariant r + n >= -2147483648;
  loop assigns r, n;
  loop variant n;
*/
  while ((n != 0))
    {
      r = (r + 1);
      n = (n - 1);
    }
  /*@ assert n == 0; */
  /*@ assert r == x + y; */
  return r;  // Dafny implicit return
}