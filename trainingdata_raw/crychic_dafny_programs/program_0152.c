// Generated C + ACSL

/*@
    requires a >= 0;
    requires b >= 0;
    assigns \nothing;
    ensures \result == a * b;
*/
int mult(int a, int b)
{
  int x = 0;
  /*@ assert x >= 0 && x <= 2147483647; */
  int y = a;
/*@
  loop invariant x == (a - y) * b;
  loop invariant 0 <= y <= \at(y, LoopEntry);
  loop invariant x == \at(x, LoopEntry) + (\at(y, LoopEntry) - y) * b;
  loop invariant \at(x, LoopEntry) + \at(y, LoopEntry) * b == x + y * b;
  loop assigns x, y;
  loop variant y;
*/
  while ((y > 0))
    {
      x = (x + b);
      y = (y - 1);
    }
  return x;  // Dafny implicit return
}
