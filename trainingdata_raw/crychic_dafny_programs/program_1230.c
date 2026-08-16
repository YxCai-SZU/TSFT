// Generated C + ACSL

/*@
    requires arr != \null;
    requires arr_len > 0;
    requires \valid(arr + (0 .. arr_len-1));
    assigns \nothing;
    ensures \forall integer k; 0 <= k < arr_len ==> arr[k] >= \result;
    ensures \exists integer j; 0 <= j < arr_len && arr[j] == \result;
*/
int Min(int *arr, int arr_len)
{
  int i = 1;
  int min = arr[0];
  /*@ assert min == arr[0]; */
/*@
  loop invariant 0 < i <= arr_len;
  loop invariant \forall integer k; 0 <= k < i ==> min <= arr[k];
  loop invariant \exists integer j; 0 <= j < i && arr[j] == min;
  loop invariant \valid(arr + (0 .. arr_len - 1));
  loop assigns i, min;
  loop variant arr_len - i;
*/
  while ((i < arr_len))
    {
      if ((arr[i] < min))
      {
        min = arr[i];
        /*@ assert min == arr[i]; */
      }
      /*@ assert \exists integer j; 0 <= j < i+1 && arr[j] == min; */
      i = (i + 1);
    }
  /*@ assert i == arr_len; */
  /*@ assert \exists integer j; 0 <= j < arr_len && arr[j] == min; */
  /*@ assert \forall integer k; 0 <= k < arr_len ==> min <= arr[k]; */
  return min;
}