// Generated C + ACSL

/*@
    requires x >= 0;
    assigns \nothing;
    ensures \result == x / 2;
*/
int Half(int x)
{
  int i = 0;
  int x1 = ((x / 2) * 2);
  /*@ assert (x1 == ((x1 / 2) * 2)); */
  /*@ assert ((x1 % 2) == 0); */
  /*@ assert ((x1 / 2) == (x / 2)); */
  int r = 0;
  /*@ assert r >= 0 && r <= 2147483647; */
/*@
  loop invariant i <= x1;
  loop invariant r == i / 2;
  loop invariant i % 2 == 0;
  loop invariant \at(i, LoopEntry) <= i;
  loop invariant i == \at(i, LoopEntry) + 2 * (r - \at(r, LoopEntry));
  loop invariant r - \at(r, LoopEntry) == (i - \at(i, LoopEntry)) / 2;
  loop assigns i, r;
  loop variant x1 - i;
*/
  while ((i < x1))
    {
      r = (r + 1);
      i = (i + 2);
    }
  return r;  // Dafny implicit return
}
