// Generated C + ACSL

/*@
    requires n >= 1 && n <= a_len;
    requires a_len > 0;
    requires \valid_read(a + (0 .. a_len-1));
    assigns \nothing;
    ensures 0 <= \result < n;
    ensures \forall integer l; 0 <= l < n ==> a[\result] >= a[l];
    ensures \exists integer l; 0 <= l < n && a[\result] == a[l];
*/
int findMax(int* a, int a_len, int n)
{
  int mi;
  int i;
  mi = 0;
  i = 0;
/*@
  loop invariant 0 <= i <= n;
  loop invariant 0 <= mi < n;
  loop invariant \forall integer l; 0 <= l < i ==> a[mi] >= a[l];
  loop invariant mi == \at(mi, LoopEntry) || (\at(mi, LoopEntry) <= mi < i && a[mi] > a[\at(mi, LoopEntry)]);
  loop assigns i, mi;
  loop variant n - i;
*/
  while ((i < n))
    {
      if ((a[i] > a[mi]))
      {
        mi = i;
      }
      i = (i + 1);
    }
  return mi;
}
