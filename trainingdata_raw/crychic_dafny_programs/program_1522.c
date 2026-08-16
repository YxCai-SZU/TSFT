// Generated C + ACSL

/*@
    requires n >= 0;
    requires d > 0;
    assigns \nothing;
*/
void intDiv(int n, int d)
{
  int q = 0;
  /*@ assert q >= 0 && q <= 2147483647; */
  int r = n;
  /*@ assert r >= 0 && r <= 2147483647; */
/*@
  loop invariant q * d + r == n;
  loop invariant r >= 0;
  loop invariant q >= \at(q, LoopEntry);
  loop invariant r <= \at(r, LoopEntry);
  loop assigns q, r;
  loop variant r - d;
*/
  while ((r >= d))
    {
      q = (q + 1);
      r = (r - d);
    }
}
