// Generated C + ACSL

/*@
    requires x >= 0;
    requires y >= 0;
    assigns \nothing;
    ensures \result == x * y;
*/
int mulitplicationRusse(int x, int y)
{
  int a = x;
  int b = y;
  int r = 0;
/*@
  loop invariant a >= 0;
  loop invariant r >= 0;
  loop invariant b >= 0;
  loop invariant r + a * b == \at(a, LoopEntry) * \at(b, LoopEntry);
  loop invariant r + a * b == x * y;
  loop assigns a, b, r;
  loop variant a;
*/
  while ((a > 0))
    {
      if (((a % 2) == 0))
      {
        b = (2 * b);
        a = (a / 2);
      }
      else
      {
        r = (r + b);
        a = (a - 1);
      }
    }
  int m = r;
  /*@ assert a == 0; */
  /*@ assert r == x * y; */
  /*@ assert m >= 0 && m <= 2147483647; */
  return m;  // Dafny implicit return
}