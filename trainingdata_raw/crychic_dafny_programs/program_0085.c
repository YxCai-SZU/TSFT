// Generated C + ACSL

/*@
    requires x >= 0;
    assigns \nothing;
    ensures \result == x * x;
*/
int Eval(int x)
{
  int y = x;
  int z = 0;
/*@
  loop invariant 0 <= y <= \at(x, LoopEntry);
  loop invariant z == \at(x, LoopEntry) * (\at(x, LoopEntry) - y);
  loop assigns y, z;
  loop variant y;
*/
  while ((y > 0))
    {
      z = (z + x);
      y = (y - 1);
    }
  return z;
}
