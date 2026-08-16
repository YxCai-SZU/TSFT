// Generated C + ACSL

/*@
  predicate sorted(int *a, integer len) =
    a != \null && \valid_read(a + (0..len-1)) &&
    \forall integer j, k; 0 <= j && j < k && k < len ==> a[j] < a[k];
*/

/*@
    requires \valid_read(a + (0 .. a_len-1));
    requires a_len >= 0;
    requires \forall integer i, j; 0 <= i < j < a_len ==> a[i] <= a[j];
    assigns \nothing;
    ensures -1 <= \result < a_len;
    ensures \result >= 0 ==> a[\result] == key;
    ensures \result == -1 ==> (\forall integer i; 0 <= i < a_len ==> a[i] != key);
*/
int BinarySearch(int *a, int a_len, int key)
{
  int lo = 0;
  int hi = a_len;
/*@
  loop invariant 0 <= lo <= hi <= a_len;
  loop invariant \forall integer i; 0 <= i < a_len && !(lo <= i < hi) ==> a[i] != key;
  loop assigns lo, hi;
  loop variant hi - lo;
*/
  while ((lo < hi))
    {
      int mid = ((lo + hi) / 2);
      if ((a[mid] < key))
      {
        lo = (mid + 1);
      }
      else
      if ((key < a[mid]))
      {
        hi = mid;
      }
      else
      {
        return mid;
      }
    }
  return -1;
}