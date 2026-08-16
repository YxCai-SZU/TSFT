// Generated C + ACSL

/*@
  predicate sortedA(int *a, integer len, integer i) =
    \forall integer k; 0 < k && k < i ==> a[k - 1] <= a[k];
*/

/*@
  predicate sorted(int *a, integer len) =
    sortedA(a, len, len);
*/

/*@
    requires 0 <= i < a_len;
    requires a != \null;
    requires \valid(a + (0 .. a_len-1));
    assigns \nothing;
    ensures i <= \result < a_len;
    ensures \forall integer k; i <= k < a_len ==> a[k] >= a[\result];
*/
int lookForMin(int* a, int a_len, int i)
{
  int j = i;
  int m = i;
  /*@ assert m >= 0 && m <= 2147483647; */
/*@
  loop invariant i <= j <= a_len;
  loop invariant i <= m < a_len;
  loop invariant \forall integer k; i <= k < j ==> a[k] >= a[m];
  loop invariant m == \at(m, LoopEntry) || (m >= \at(j, LoopEntry) && m < j);
  loop assigns j, m;
  loop variant a_len - j;
*/
  while ((j < a_len))
    {
      if ((a[j] < a[m]))
      {
        m = j;
      }
      j = (j + 1);
    }
  return m;
}

/*@
    requires a != \null;
    requires a_len >= 0;
    requires \valid(a + (0 .. a_len-1));
    assigns a[0 .. a_len-1];
    ensures \forall integer i, j; 0 <= i <= j < a_len ==> a[i] <= a[j];
*/
void insertionSort(int* a, int a_len)
{
  int c = 0;
/*@
  loop invariant 0 <= c <= a_len;
  loop invariant \forall integer k, l;
                 0 <= k < c && c <= l < a_len ==> a[k] <= a[l];
  loop invariant \forall integer i, j;
                 0 <= i < j && j < c ==> a[i] <= a[j];
  loop assigns c, a[0..a_len-1];
  loop variant a_len - c;
*/
  while ((c < a_len))
    {
      int m = lookForMin(a, a_len, c);
      int temp = a[m];
      a[m] = a[c];
      a[c] = temp;
      /*@ assert \forall integer k; c <= k < a_len ==> a[k] >= a[c]; */
      c = (c + 1);
    }
}