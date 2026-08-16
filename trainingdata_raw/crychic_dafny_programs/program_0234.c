// Generated C + ACSL

/*@
    requires n > 0;
    requires k > n;
    assigns \nothing;
    ensures \result >= 0;
    ensures \result == k - n;
*/
int dafny_main(int n, int k)
{
  int k_out = k;
  /*@ assert k_out >= 0 && k_out <= 2147483647; */
  int j = 0;
/*@
  loop invariant 0 <= j <= n;
  loop invariant k_out == \at(k_out, LoopEntry) - j;
  loop invariant k_out == \at(k_out, LoopEntry) - (j - \at(j, LoopEntry));
  loop invariant j + k_out == \at(j, LoopEntry) + \at(k_out, LoopEntry);
  loop assigns j, k_out;
  loop variant n - j;
*/
  while ((j < n))
    {
      j = (j + 1);
      k_out = (k_out - 1);
    }
  return k_out;  // Dafny implicit return
}
