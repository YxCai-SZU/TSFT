// Generated C + ACSL

/*@
    requires a >= 0;
    assigns \nothing;
*/
void mystery(int a)
{
  int q = 0;
  int r = a + 1;
/*@
  loop invariant 0 < r <= \at(a, LoopEntry) + 1;
  loop invariant a == q * 3 + r - 1;
  loop invariant q >= \at(q, LoopEntry);
  loop invariant r <= \at(r, LoopEntry);
  loop invariant a == \at(a, LoopEntry);
  loop assigns q, r;
  loop variant r;
*/
  while ((r >= 4))
    {
      /*@ assert (a == (((q * 3) + r) - 1)); */
      /*@ assert (a == ((((q * 3) + (r - (r % 4))) + (r % 4)) - 1)); */
      /*@ assert (a == (((q * 3) + ((((r - (r % 4)) * 4) + ((r % 4) * 4)) / 4)) - 1)); */
      /*@ assert (a == (((q * 3) + ((((((r - (r % 4)) * 3) + r) - (r % 4)) + ((r % 4) * 4)) / 4)) - 1)); */
      /*@ assert (a == (((q * 3) + (((((((r / 4) * 4) * 3) + r) - (r % 4)) + ((r % 4) * 4)) / 4)) - 1)); */
      /*@ assert (a == (((q * 3) + ((((((r / 4) * 3) * 4) + ((r / 4) * 4)) + ((r % 4) * 4)) / 4)) - 1)); */
      /*@ assert (a == (((((q * 3) + ((r / 4) * 3)) + (r / 4)) + (r % 4)) - 1)); */
      /*@ assert (a == (((((q + (r / 4)) * 3) + (r / 4)) + (r % 4)) - 1)); */
      q = (q + (r / 4));
      /*@ assert q >= 0 && q <= 2147483647; */
      /*@ assert (a == ((((q * 3) + (r / 4)) + (r % 4)) - 1)); */
      r = ((r / 4) + (r % 4));
      /*@ assert r >= 0 && r <= 2147483647; */
      /*@ assert (a == (((q * 3) + r) - 1)); */
    }
  /*@ assert (a == (((q * 3) + r) - 1)); */
  r = (r - 1);
  /*@ assert (a == ((q * 3) + r)); */
}