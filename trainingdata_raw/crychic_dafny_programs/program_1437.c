// Generated C + ACSL

/*@
    requires arr != \null;
    requires arr_len > 0;
    requires \valid_read(arr + (0 .. arr_len-1));
    requires \forall integer i; 0 <= i && i < arr_len - 1 ==> arr[i + 1] > arr[i];
    assigns \nothing;
    ensures \result == -1 || (0 <= \result && \result < arr_len && arr[\result] == target);
*/
int BinarySearch(int* arr, int arr_len, int target)
{
  int hi = arr_len;
  /*@ assert hi >= 0 && hi <= 2147483647; */
  int lo = 0;
  /*@ assert lo >= 0 && lo <= 2147483647; */
/*@
  loop invariant 0 <= lo && lo <= hi && hi <= arr_len;
  loop invariant \at(lo, LoopEntry) <= lo;
  loop invariant hi <= \at(hi, LoopEntry);
  loop invariant \forall integer k; 0 <= k && k < \at(lo, LoopEntry) ==> arr[k] < target;
  loop invariant \forall integer k; \at(hi, LoopEntry) <= k && k < arr_len ==> arr[k] > target;
  loop assigns lo, hi;
  loop variant hi - lo;
*/
  while ((lo < hi))
    {
      int index = ((hi + lo) / 2);
      /*@ assert index >= 0 && index <= 2147483647; */
      if ((arr[index] < target))
      {
        lo = (index + 1);
      }
      else
      if ((arr[index] > target))
      {
        hi = index;
      }
      else
      {
        return index;
      }
    }
  return -1;
}