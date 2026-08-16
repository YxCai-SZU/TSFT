// Generated C + ACSL

/*@
  predicate sorted_between(int *a, integer len, integer from, integer to) =
    \forall integer i, j; from <= i && i < j && j < to && 0 <= i && i < j && j < len ==> a[i] <= a[j];
*/

/*@
  predicate sorted(int *a, integer len) =
    sorted_between(a, len, 0, len);
*/

/*@
    requires a != \null;
    requires a_len > 0;
    requires \valid(a + (0 .. a_len-1));
    assigns a[0 .. a_len-1];
    ensures \forall integer i, j; 0 <= i && i < j && j < a_len ==> a[i] <= a[j];
*/
void bubbleSort(int* a, int a_len)
{
  int i = 1;
  /*@ assert i >= 0 && i <= 2147483647; */
/*@
  loop invariant 0 <= i <= a_len;
  loop invariant \forall integer k1, k2;
    0 <= k1 && k1 < k2 && k2 < i ==> a[k1] <= a[k2];
  loop assigns i, a[0 .. a_len - 1];
  loop variant a_len - i;
*/
  while ((i < a_len))
    {
      int j = i;
      /*@ assert j >= 0 && j <= 2147483647; */
/*@
  loop invariant 0 <= j <= \at(i, LoopEntry);
  loop invariant \forall integer k1, k2;
    0 <= k1 && k1 < k2 && k2 < j ==> a[k1] <= a[k2];
  loop invariant \forall integer u, v;
    0 <= u && u < j && j < v && v <= \at(i, LoopEntry) ==> a[u] <= a[v];
  loop invariant \forall integer k1, k2;
    j <= k1 && k1 < k2 && k2 <= \at(i, LoopEntry) ==> a[k1] <= a[k2];
  loop assigns j, a[0 .. \at(i, LoopEntry)];
  loop variant j;
*/
      while ((j > 0))
        {
          if ((a[(j - 1)] > a[j]))
          {
            int temp = a[(j - 1)];
            a[(j - 1)] = a[j];
            a[j] = temp;
          }
          j = (j - 1);
        }
      i = (i + 1);
    }
}