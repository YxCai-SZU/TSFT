// Generated C + ACSL

/*@
    requires n >= 0;
    assigns \nothing;
    ensures \result == n * n;
*/
int square(int n)
{
  int x;
  int i;
  int r = 0;
  /*@ assert r >= 0 && r <= 2147483647; */
  i = 0;
  x = 1;
/*@
  loop invariant i <= n;
  loop invariant r == i * i;
  loop invariant x == 2 * i + 1;
  loop assigns i, r, x;
  loop variant n - i;
*/
  while ((i < n))
    {
      r = (r + x);
      x = (x + 2);
      i = (i + 1);
    }
  return r;  // Dafny implicit return
}
