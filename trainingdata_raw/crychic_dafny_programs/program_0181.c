// Generated C + ACSL

/*@
    requires y != 0;
    requires x >= 0;
    requires y >= 0;
    assigns \nothing;
*/
void Quotient(int x, int y)
{
  int r = x;
  /*@ assert r >= 0 && r <= 2147483647; */
  int q = 0;
  /*@ assert q >= 0 && q <= 2147483647; */
/*@
  loop invariant q * y + r == x;
  loop invariant r >= 0;
  loop invariant y > 0;
  loop invariant q >= \at(q, LoopEntry);
  loop invariant r <= \at(r, LoopEntry);
  loop assigns q, r;
  loop variant r;
*/
  while ((y <= r))
    {
      r = (r - y);
      q = (q + 1);
    }
}
