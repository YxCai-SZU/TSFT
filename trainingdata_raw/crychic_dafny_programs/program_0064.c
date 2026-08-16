// Generated C + ACSL

/*@
    requires arr != \null;
    requires arr_len >= 0;
    requires \valid_read(arr + (0 .. arr_len-1));
    requires \forall integer i, j; 0 <= i < j < arr_len ==> arr[i] <= arr[j];
    assigns \nothing;
    ensures (0 <= \result < arr_len) ==> arr[\result] == target;
    ensures (\result == -1) ==> (\forall integer i; 0 <= i < arr_len ==> arr[i] != target);
    ensures \forall integer i; 0 <= i < arr_len ==> arr[i] == \old(arr[i]);
*/
int FindFirstOccurrence(int* arr, int arr_len, int target)
{
  int index = -1;
  /*@ assert -1 <= index <= 2147483647; */
  /*@ assert arr_len >= 0; */
  {
    int i = 0;
/*@
  loop invariant 0 <= i <= arr_len;
  loop invariant -1 <= index < arr_len;
  loop invariant index == -1 ==> \forall integer k; 0 <= k < i ==> arr[k] != target;
  loop invariant index >= 0 ==> (0 <= index < i && arr[index] == target);
  loop invariant index >= 0 ==> (\forall integer k; 0 <= k < index ==> arr[k] != target);
  loop invariant index == -1 ==> (\forall integer k; 0 <= k < i && arr[k] < target ==> arr[k] != target);
  loop invariant i > 0 && i < arr_len && arr[i-1] > target ==> (\forall integer k; i <= k < arr_len ==> arr[k] > target);
  loop invariant \forall integer k; 0 <= k < arr_len ==> arr[k] == \at(arr[k], LoopEntry);
  loop assigns i, index;
  loop variant arr_len - i;
*/
    while ((i < arr_len))
      {
        /*@ assert 0 <= i < arr_len; */
        /*@ assert \valid_read(&arr[i]); */
        if ((arr[i] == target))
        {
          /*@ assert arr[i] == target; */
          index = i;
          /*@ assert index >= 0 && arr[index] == target; */
          break;;
        }
        if ((arr[i] > target))
        {
          /*@ assert arr[i] > target; */
          /*@ assert \forall integer k; i <= k < arr_len ==> arr[k] >= arr[i]; */
          break;;
        }
        /*@ assert arr[i] < target; */
        i = (i + 1);
      }
  }
  /*@ assert index == -1 ==> (\forall integer k; 0 <= k < arr_len ==> arr[k] != target); */
  /*@ assert index >= 0 ==> (0 <= index < arr_len && arr[index] == target); */
  return index;  // Dafny implicit return
}