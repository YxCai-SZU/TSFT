// Generated C + ACSL

/*@
  predicate Par(integer n) =
    n % 2 == 0;
*/

/*@
    requires a >= b;
    requires Par(a - b);
    requires 0 <= a <= 2147483647;
    requires 0 <= b <= 2147483647;
    assigns \nothing;
*/
void FazAlgo(int a, int b)
{
  int x = a;
  /*@ assert x == a; */
  /*@ assert x >= 0 && x <= 2147483647; */
  int y = b;
  /*@ assert y == b; */
  /*@ assert y >= 0 && y <= 2147483647; */
/*@
  loop invariant x >= y;
  loop invariant (x - y) % 2 == \at(x - y, LoopEntry) % 2;
  loop invariant x + y == \at(x, LoopEntry) + \at(y, LoopEntry);
  loop invariant x - y >= 0;
  loop invariant x - y <= \at(x - y, LoopEntry);
  loop invariant 0 <= x <= 2147483647;
  loop invariant 0 <= y <= 2147483647;
  loop invariant x + y == a + b;
  loop assigns x, y;
  loop variant x - y;
*/
  while ((x != y))
    {
      x = (x - 1);
      y = (y + 1);
    }
}