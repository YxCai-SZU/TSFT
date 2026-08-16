// Generated C + ACSL

/*@
    requires arr != \null;
    requires arr_len >= 0;
    requires \valid_read(arr + (0 .. arr_len-1));
    requires \forall integer i, j; 0 <= i < j < arr_len ==> arr[i] != arr[j];
    requires \forall integer i, j; 0 <= i < j < arr_len ==> arr[i] < arr[j];
    assigns \nothing;
    ensures -1 <= \result < arr_len;
    ensures \result == -1 ==> (\forall integer i; 0 <= i < arr_len ==> arr[i] != target);
    ensures \result != -1 ==> (0 <= \result < arr_len && arr[\result] == target);
*/
int BinarySearch(int* arr, int arr_len, int target)
{
  int low = 0;
  int high = (arr_len - 1);
/*@
  loop invariant 0 <= low <= high + 1;
  loop invariant low - 1 <= high < arr_len;
  loop invariant \forall integer i; 0 <= i < low ==> arr[i] != target;
  loop invariant \forall integer i; high < i < arr_len ==> arr[i] != target;
  loop assigns low, high;
  loop variant high - low + 1;
*/
  while ((low <= high))
    {
      int mid = ((low + high) / 2);
      if ((arr[mid] == target))
      {
        return mid;
      }
      else
      if ((arr[mid] < target))
      {
        low = (mid + 1);
      }
      else
      {
        high = (mid - 1);
      }
    }
  return -1;
}

/*@
  predicate sorted(int *a, integer len) =
    \forall integer j, k; 0 <= j && j < k && k < len ==> a[j] <= a[k];
*/

/*@
  predicate distinct(int *arr, integer len) =
    \forall integer i, j; 0 <= i && i < len && 0 <= j && j < len && i != j ==> arr[i] != arr[j];
*/

/*@
  predicate not_found(int *arr, integer len, integer target) =
    \forall integer j; 0 <= j && j < len ==> arr[j] != target;
*/

/*@
  predicate found(int *arr, integer len, integer target, integer index) =
    -1 <= index && index < len &&
    (index == -1 ? \false : (arr[index] == target ? \true : \false));
*/