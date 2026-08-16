// Generated C + ACSL

/*@
    requires \valid(a + (0 .. n-1));
    requires n > 0;
    assigns \nothing;
    ensures 0 <= \result < n;
    ensures \forall integer l; 0 <= l < n ==> a[l] <= a[\result];
*/
int findMax(int *a, int n)
{
  int mi;
  int i;
  mi = 0;
  i = 0;
/*@
  loop invariant 0 <= i <= n;
  loop invariant 0 <= mi < n;
  loop invariant \forall integer k; 0 <= k < i ==> a[k] <= a[mi];
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