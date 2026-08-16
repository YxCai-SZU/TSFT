// Generated C + ACSL

/*@
    requires 0 <= n;
    assigns \nothing;
    ensures \result == 2 * n;
*/
int Multiply2(int n)
{
  int r = 0;
  /*@ assert r >= 0 && r <= 2147483647; */
  int i = 0;
/*@
  loop invariant 0 <= i <= n;
  loop invariant r == 2 * i;
  loop assigns i, r;
  loop variant n - i;
*/
  while ((i < n))
    {
      r = (r + 2);
      i = (i + 1);
    }
  return r;  // Dafny implicit return
}
