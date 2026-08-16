// Generated C + ACSL

/*@
  predicate sorted_prime(int *a, integer len, integer i) =
    \forall integer k; 0 < k && k < i ==> a[k - 1] <= a[k];
*/

/*@
  predicate sorted(int *a, integer len) =
    sorted_prime(a, len, len);
*/

/*@
    requires a != \null;
    requires a_len >= 0;
    requires \valid(a + (0 .. a_len-1));
    assigns a[0 .. a_len-1];
*/
void SelectionSort(int* a, int a_len)
{
  int n = 0;
/*@
  loop invariant 0 <= n <= a_len;
  loop invariant \forall integer i, j; 0 <= i < n <= j < a_len ==> a[i] <= a[j];
  loop invariant \forall integer k1, k2; 0 <= k1 < k2 < n ==> a[k1] <= a[k2];
  loop assigns n, a[0..a_len-1];
  loop variant a_len - n;
*/
  while ((n != a_len))
    {
      int mindex = n;
      int m = (n + 1);
/*@
  loop invariant n <= m <= a_len;
  loop invariant n <= mindex < m;
  loop invariant \forall integer i; n <= i < m ==> a[mindex] <= a[i];
  loop invariant mindex == \at(mindex, LoopEntry) ||
                 (\exists integer k; \at(m, LoopEntry) <= k < m && mindex == k);
  loop invariant \forall integer i; n <= i < \at(m, LoopEntry) ==>
                 a[\at(mindex, LoopEntry)] <= a[i];
  loop assigns m, mindex;
  loop variant a_len - m;
*/
      while ((m != a_len))
        {
          if ((a[m] < a[mindex]))
          {
            mindex = m;
          }
          m = (m + 1);
        }
      /* swap a[n] and a[mindex] */
      int temp = a[n];
      a[n] = a[mindex];
      a[mindex] = temp;
      n = (n + 1);
    }
}