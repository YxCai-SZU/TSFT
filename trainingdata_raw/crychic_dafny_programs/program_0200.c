// Generated C + ACSL

/*@
    requires n >= 0;
    requires k == 1 || k >= 0;
    assigns \nothing;
*/
void dafny_main(int n, int k)
{
  int i = 0;
  /*@ assert i >= 0 && i <= 2147483647; */
  int j = 0;
  /*@ assert j >= 0 && j <= 2147483647; */
/*@
  loop invariant 0 <= i <= n;
  loop invariant j == i * (i + 1) / 2;
  loop invariant 2 * j == i * (i + 1);
  loop invariant i == \at(i, LoopEntry) + (\at(i, LoopEntry) < n ? (i - \at(i, LoopEntry)) : 0);
  loop invariant j == \at(j, LoopEntry) + (i * (i + 1) / 2 - \at(i, LoopEntry) * (\at(i, LoopEntry) + 1) / 2);
  loop assigns i, j;
  loop variant n - i;
*/
  while ((i < n))
    {
      /*@ assert j == i * (i + 1) / 2; */
      /*@ assert 2 * j == i * (i + 1); */
      int old_i = i;
      int old_j = j;
      /*@ assert old_j == old_i * (old_i + 1) / 2; */
      i = (i + 1);
      /*@ assert i == old_i + 1; */
      j = (j + i);
      /*@ assert j == old_j + i; */
      /*@ assert j == old_j + (old_i + 1); */
      /*@ assert j == old_i * (old_i + 1) / 2 + (old_i + 1); */
      /*@ assert 2 * j == old_i * (old_i + 1) + 2 * (old_i + 1); */
      /*@ assert 2 * j == (old_i + 1) * (old_i + 2); */
      /*@ assert 2 * j == i * (i + 1); */
      /*@ assert j == i * (i + 1) / 2; */
    }
}