// Generated C + ACSL

/*@
    requires 0 <= i < j <= a_len;
    requires a != \null;
    requires \valid_read(a + (0 .. a_len-1));
    assigns \nothing;
    ensures i <= \result < j;
    ensures \forall integer k; i <= k < j ==> a[\result] <= a[k];
*/
int findmin(int* a, int a_len, int i, int j)
{
  int m = i;
  /*@ assert m >= 0 && m <= 2147483647; */
  int index = (i + 1);
/*@
  loop invariant i + 1 <= index <= j;
  loop invariant i <= m < j;
  loop invariant \forall integer k; i <= k < index ==> a[m] <= a[k];
  loop invariant m == \at(m, LoopEntry) || (index > i + 1 && \exists integer k; \at(m, LoopEntry) < k < index && m == k);
  loop assigns index, m;
  loop variant j - index;
*/
  while ((index < j))
    {
      if ((a[index] < a[m]))
      {
        m = index;
      }
      index = (index + 1);
    }
  return m;  // Dafny implicit return
}
