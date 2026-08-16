// Generated C + ACSL

/*@
    requires arr != \null;
    requires arr_len >= 0;
    requires \valid_read(arr + (0 .. arr_len-1));
    requires \forall integer i, j; 0 <= i < j < arr_len ==> arr[i] <= arr[j];
    assigns \nothing;
    ensures (\result >= 0 && \result < arr_len) ==> arr[\result] == target;
    ensures (\result == -1) ==> (\forall integer i; 0 <= i < arr_len ==> arr[i] != target);
    ensures \result >= -1 && \result < arr_len;
*/
int BinarySearch(int* arr, int arr_len, int target)
{
  int left = 0;
  int right = (arr_len - 1);
/*@
  loop invariant 0 <= left <= arr_len;
  loop invariant -1 <= right < arr_len;
  loop invariant \forall integer i; 0 <= i < arr_len && arr[i] == target ==> left <= i <= right;
  loop invariant \forall integer i; 0 <= i < left ==> arr[i] < target;
  loop invariant \forall integer i; right < i < arr_len ==> arr[i] > target;
  loop assigns left, right;
  loop variant right - left + 1;
*/
  while ((left <= right))
    {
      int mid = (left + ((right - left) / 2));
      if (arr[mid] == target)
      {
        return mid;
      }
      else
      if ((arr[mid] < target))
      {
        left = (mid + 1);
      }
      else
      {
        right = (mid - 1);
      }
    }
  return -1;
}

/*@
    assigns \nothing;
*/
void TestBinarySearch(void)
{
  int arr1[5] = {1, 2, 3, 4, 5};
  int result1 = BinarySearch(arr1, 5, 3);
  /*@ assert (arr1[2] == 3); */
  /*@ assert (result1 >= 0 && result1 == 2); */
  int result2 = BinarySearch(arr1, 5, 6);
  /*@ assert result2 == -1; */
  int arr2[1] = {0};
  int result3 = BinarySearch(arr2, 1, 1);
  /*@ assert result3 == -1; */
}