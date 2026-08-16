// Generated C + ACSL

/*@
    requires n > 0;
    requires n <= a_len;
    requires a != \null;
    requires \valid_read(a + (0 .. n-1));
    requires \forall integer i; 0 <= i < n ==> a[i] <= max;
    assigns \nothing;
    ensures \result <= max * n;
*/
int add_small_numbers(int* a, int a_len, int n, int max)
{
  int i;
  i = 0;
  int r = 0;
  /*@ assert r >= 0 && r <= 2147483647; */
/*@
  loop invariant i <= n;
  loop invariant r <= max * i;
  loop invariant \at(i, LoopEntry) <= i;
  loop assigns i, r;
  loop variant n - i;
*/
  while ((i < n))
    {
      r = (r + a[i]);
      i = (i + 1);
    }
  return r;  // Dafny implicit return
}
