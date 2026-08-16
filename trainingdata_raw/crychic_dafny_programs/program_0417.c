// Generated C + ACSL

/*@
  predicate sorted(int *a, integer len) =
    \forall integer j, k; 0 <= j && j < k && k < len ==> a[j] <= a[k];
*/

/*@
    requires a != \null;
    requires a_len >= 0;
    requires \valid(a + (0 .. a_len-1));
    requires \forall integer i, j; 0 <= i < j < a_len ==> a[i] <= a[j];
    assigns \nothing;
    ensures \result >= 0 ==> \result < a_len && a[\result] == value;
    ensures \result < 0 ==> \forall integer k; 0 <= k < a_len ==> a[k] != value;
*/
int BinarySearch(int *a, int a_len, int value)
{
  int low = 0;
  int high = a_len;
/*@
  loop invariant 0 <= low <= high <= a_len;
  loop invariant \forall integer i; 0 <= i < a_len && !(low <= i < high) ==> a[i] != value;
  loop assigns low, high;
  loop variant high - low;
*/
  while ((low < high))
    {
      int mid = ((low + high) / 2);
      if ((a[mid] < value))
      {
        low = (mid + 1);
      }
      else
      if ((value < a[mid]))
      {
        high = mid;
      }
      else
      {
        return mid;
      }
    }
  return -1;
}