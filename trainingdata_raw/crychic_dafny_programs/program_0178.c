// Generated C + ACSL

/*@
    requires xInit >= 0;
    requires y >= 0;
    assigns \nothing;
    ensures \result == 0;
*/
int Main(int xInit, int y)
{
  int x = xInit;
  int z = (x * y);
  /*@ assert z >= 0 && z <= 2147483647; */
  /*@ assert z == xInit * y; */
/*@
  loop invariant x >= 0;
  loop invariant z == x * y;
  loop invariant y == \at(y, LoopEntry);
  loop invariant xInit == \at(xInit, LoopEntry);
  loop invariant \at(z, LoopEntry) == xInit * y;
  loop assigns x, z;
  loop variant x;
*/
  while ((x > 0))
    {
      x = (x - 1);
      z = (z - y);
      /*@ assert z == x * y; */
    }
  /*@ assert x == 0; */
  /*@ assert z == x * y; */
  /*@ assert z == 0 * y; */
  /*@ assert z == 0; */
  return z;  // Dafny implicit return
}