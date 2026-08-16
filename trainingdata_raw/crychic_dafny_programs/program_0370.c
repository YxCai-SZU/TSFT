// Generated C + ACSL

/*@
    requires a != \null;
    requires a_len > 0;
    requires \valid_read(a + (0 .. a_len-1));
    requires \forall integer i, j; 0 <= i < j < a_len ==> a[i] <= a[j];
    assigns \nothing;
    ensures -1 <= \result < a_len;
    ensures 0 <= \result < a_len ==> a[\result] == value;
    ensures \result == -1 ==> (\forall integer k; 0 <= k < a_len ==> a[k] != value);
*/
int BinarySearch(int* a, int a_len, int value)
{
  int low = 0;
  int high = a_len;
/*@
  loop invariant 0 <= low <= high <= a_len;
  loop invariant \forall integer k; 0 <= k < a_len && !(low <= k < high) ==> a[k] != value;
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