// Generated C + ACSL

/*@
    requires x >= 0;
    requires y > 0;
    assigns \nothing;
*/
void Division(int x, int y)
{
  int q = 0;
  /*@ assert q >= 0 && q <= 2147483647; */
  int r = x;
  /*@ assert r >= 0 && r <= 2147483647; */
/*@
  loop invariant q * y + r == x;
  loop invariant r >= 0;
  loop invariant q >= \at(q, LoopEntry);
  loop invariant r <= \at(r, LoopEntry);
  loop assigns q, r;
  loop variant r;
*/
  while ((r >= y))
    {
      r = (r - y);
      q = (q + 1);
    }
}
