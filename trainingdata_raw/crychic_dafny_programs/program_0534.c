// Generated C + ACSL

/*@
    requires n >= 0;
    assigns \nothing;
    ensures \result == n;
*/
int CountToAndReturnN(int n)
{
  int i = 0;
/*@
  loop invariant 0 <= i <= n;
  loop assigns i;
  loop variant n - i;
*/
  while ((i < n))
    {
      i = (i + 1);
    }
  int r = i;
  /*@ assert r >= 0 && r <= 2147483647; */
  return r;  // Dafny implicit return
}
