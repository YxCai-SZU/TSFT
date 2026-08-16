// Generated C + ACSL

/*@
    requires n >= 0;
    assigns \nothing;
    ensures \result >= 0;
    ensures \result * \result <= n < (\result + 1) * (\result + 1);
*/
int mroot1(int n)
{
  int r = 0;
  /*@ assert r >= 0 && r <= 2147483647; */
/*@
  loop invariant r >= 0;
  loop invariant r * r <= n;
  loop invariant (r + 1) * (r + 1) > n ==> \at(r, LoopEntry) <= r;
  loop assigns r;
  loop variant n - r * r;
*/
  while ((((r + 1) * (r + 1)) <= n))
    {
      r = (r + 1);
    }
  return r;  // Dafny implicit return
}

/*@
    requires n >= 0;
    assigns \nothing;
    ensures \result >= 0;
    ensures \result * \result <= n < (\result + 1) * (\result + 1);
*/
int mroot2(int n)
{
  int r = n;
  /*@ assert r >= 0 && r <= 2147483647; */
/*@
  loop invariant 0 <= r <= \at(n, LoopEntry);
  loop invariant \at(n, LoopEntry) < (r + 1) * (r + 1);
  loop invariant r * r <= \at(n, LoopEntry) ==> \at(n, LoopEntry) < (r + 1) * (r + 1);
  loop assigns r;
  loop variant r;
*/
  while ((n < (r * r)))
    {
      r = (r - 1);
    }
  return r;  // Dafny implicit return
}

/*@
    requires n >= 0;
    assigns \nothing;
    ensures \result >= 0;
    ensures \result * \result <= n < (\result + 1) * (\result + 1);
*/
int mroot3(int n)
{
  int y;
  int h;
  int r = 0;
  /*@ assert r >= 0 && r <= 2147483647; */
  y = (n + 1);
  /*@ assert r == 0; */
  /*@ assert y == n + 1; */
  /*@ assert y >= r + 1; */
/*@
  loop invariant r >= 0;
  loop invariant r * r <= n;
  loop invariant n < y * y;
  loop invariant r < y;
  loop invariant y >= r + 1;
  loop invariant \at(r, LoopEntry) <= r <= \at(y, LoopEntry);
  loop invariant \at(r, LoopEntry) <= y <= \at(y, LoopEntry);
  loop assigns r, y, h;
  loop variant y - r;
*/
  while ((y != (r + 1)))
    {
      h = ((r + y) / 2);
      /*@ assert r < y; */
      /*@ assert r <= h < y; */
      if (((h * h) <= n))
      {
        /*@ assert h * h <= n; */
        /*@ assert n < y * y; */
        r = h;
        /*@ assert r < y; */
        /*@ assert y >= r + 1; */
      }
      else
      {
        /*@ assert h * h > n; */
        /*@ assert r * r <= n; */
        y = h;
        /*@ assert r < y; */
        /*@ assert y >= r + 1; */
      }
    }
  return r;  // Dafny implicit return
}