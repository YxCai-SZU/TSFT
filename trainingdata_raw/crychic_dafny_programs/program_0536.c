// Generated C + ACSL

/*@
    requires a != \null;
    requires a_len > 0;
    requires 0 < n <= a_len;
    requires \valid(a + (0 .. a_len-1));
    assigns \nothing;
    ensures 0 <= \result < n;
    ensures \forall integer k; 0 <= k < n ==> a[\result] >= a[k];
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
  loop invariant \forall integer k; 0 <= k < i ==> a[mi] >= a[k];
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
