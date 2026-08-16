// Generated C + ACSL

/*@
    requires x >= 0;
    requires y > 0;
    assigns \nothing;
*/
void CalculaQuociente(int x, int y)
{
  int d = 0;
  /*@ assert d >= 0 && d <= 2147483647; */
  int r = x;
  /*@ assert r >= 0 && r <= 2147483647; */
/*@
  loop invariant x == y * d + r;
  loop invariant r >= 0;
  loop invariant d >= \at(d, LoopEntry);
  loop invariant r <= \at(r, LoopEntry);
  loop assigns r, d;
  loop variant r - y;
*/
  while ((r >= y))
    {
      r = (r - y);
      d = (d + 1);
    }
}
