// Generated C + ACSL

/*@
    requires arr_len > 0;
    requires \valid(arr + (0 .. arr_len-1));
    assigns \nothing;
    ensures \forall integer i; 0 <= i < arr_len ==> \result >= arr[i];
    ensures \exists integer i; 0 <= i < arr_len && \result == arr[i];
*/
int FindMax(int* arr, int arr_len)
{
  int max = arr[0];
  /*@ assert max == arr[0]; */
  /*@ assert \exists integer k; k == 0 && max == arr[k]; */
  int i = 1;
/*@
  loop invariant 1 <= i <= arr_len;
  loop invariant \forall integer k; 0 <= k < i ==> max >= arr[k];
  loop invariant \exists integer k; 0 <= k < i && max == arr[k];
  loop invariant \valid_read(arr + (0..arr_len-1));
  loop assigns i, max;
  loop variant arr_len - i;
*/
  while ((i < arr_len))
    {
      if ((arr[i] > max))
      {
        max = arr[i];
        /*@ assert max == arr[i]; */
        /*@ assert \exists integer k; k == i && max == arr[k]; */
      }
      /*@ assert max >= arr[i]; */
      /*@ assert \forall integer k; 0 <= k <= i ==> max >= arr[k]; */
      i = (i + 1);
    }
  /*@ assert i == arr_len; */
  /*@ assert \forall integer k; 0 <= k < arr_len ==> max >= arr[k]; */
  /*@ assert \exists integer k; 0 <= k < arr_len && max == arr[k]; */
  return max;  // Dafny implicit return
}