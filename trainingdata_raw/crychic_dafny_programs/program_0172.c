// Generated C + ACSL

/*@
    requires arr != \null;
    requires 0 <= i < arr_len && 0 <= j < arr_len;
    requires \valid(arr + (0 .. arr_len-1));
    assigns arr[0 .. arr_len-1];
    ensures arr[i] == \old(arr[j]) && arr[j] == \old(arr[i]);
    ensures \forall integer k; 0 <= k < arr_len && k != i && k != j ==> arr[k] == \old(arr[k]);
*/
void swap(int* arr, int arr_len, int i, int j)
{
  int tmp = arr[i];
  arr[i] = arr[j];
  arr[j] = tmp;
}
